#include "Application.h"
#include "logging.h"

namespace CC
{
    Application::Application()
    {
        m_Window = std::unique_ptr<Window>(Window::Create());
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
}