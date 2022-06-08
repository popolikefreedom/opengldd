#include "Application.h"
#include "logging.h"

namespace CC
{
    Application::Application()
    {
        m_Window = std::unique_ptr<Window>(Window::Create());
        m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
    }

    Application::~Application()
    {
        
    }

    void Application::run()
    {
        LOGI("hello world")
        while (m_Running)
        {
            m_Window->OnUpdate();
        }
        
    }

    void Application::OnEvent(Event& e)
    {
        LOGI("on OnEvent {0}", e.ToString());
        EventDispatcher dispatcher(e);
        dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));
    }

    bool Application::OnWindowClose(WindowCloseEvent& e)
    {
        m_Running = false;
        return true;
    }
}