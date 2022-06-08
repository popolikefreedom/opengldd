#include "LinuxWindows.h"
#include "../logging.h"
#include "../event/ApplicationEvent.h"
#include "../event/KeyEvent.h"

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

        // set glfw callbacks
        glfwSetWindowCloseCallback(m_Window, [](GLFWwindow *window)
                                   {
            WindowData& data = *(WindowData *)glfwGetWindowUserPointer(window);
            WindowCloseEvent event;
            data.callback(event); });

        glfwSetKeyCallback(m_Window, [](GLFWwindow *window, int key, int scancode, int action, int mods)
                           {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			switch (action)
			{
				case GLFW_PRESS:
				{
					KeyPressedEvent event(key, 0);
					data.callback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					KeyReleasedEvent event(key);
					data.callback(event);
					break;
				}
				case GLFW_REPEAT:
				{
					KeyPressedEvent event(key, 1);
					data.callback(event);
					break;
				}
			} });
    }

    void LinuxWindows::shutDown()
    {
        glfwDestroyWindow(m_Window);
    }

    void LinuxWindows::OnUpdate()
    {
        glClearColor(1, 0, 1, 1);
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

    void LinuxWindows::SetEventCallback(const EventCallbackFn &callback)
    {
        m_Data.callback = callback;
    }
}