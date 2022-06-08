#include "LinuxWindows.h"
#include "../logging.h"

namespace CC
{

    static bool s_GLFWInitialized = false;

    Window *Window::Create(const WindowProps &props)
    {
        return new LinuxWindows(props);
    }

    LinuxWindows::LinuxWindows(const WindowProps &props)
    {
        Init(props);
    }

    LinuxWindows::~LinuxWindows()
    {
        shutDown();
    }

    void LinuxWindows::Init(const WindowProps &props)
    {
        m_Data.Title = props.Title;
        m_Data.Height = props.Height;
        m_Data.Width = props.Width;

        LOGI("init Window {0}, {1}, {2}", props.Title, props.Width, props.Height);
        if (!s_GLFWInitialized)
        {
            int success = glfwInit();

            s_GLFWInitialized = true;
        }

        m_Window = glfwCreateWindow(props.Width, props.Height, m_Data.Title.c_str(), nullptr, nullptr);
        glfwMakeContextCurrent(m_Window);
        glfwSetWindowUserPointer(m_Window, &m_Data);
        SetVSync(true);
    }


    void LinuxWindows::shutDown()
    {
        glfwDestroyWindow(m_Window);
    }

    void LinuxWindows::OnUpdate()
    {
        glClearColor(1,0,1,1);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwPollEvents();
        glfwSwapBuffers(m_Window);
    }

    void LinuxWindows::SetVSync(bool enabled)
    {
        glfwSwapInterval(enabled ? 1 : 0);
        m_Data.VSync = enabled;
    }

    bool LinuxWindows::IsVSync() const
    {
        return m_Data.VSync;
    }
}