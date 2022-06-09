#include "Application.h"
#include "logging.h"
#include "Imgui/ImguiLayer.h"

namespace CC
{
    Application *Application::application;

    Application::Application()
    {
        assert(!application);
        application = this;
        m_Window = Window::Create();
        m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
        PushOverlay(new ImguiLayer());
    }

    Application::~Application()
    {
    }

    void Application::run()
    {
        LOGI("hello world")
        while (m_Running)
        {
            for (Layers *layer : m_LayerStack)
            {
                layer->OnUpdate();
            }
            // LOGI("update")
            m_Window->OnUpdate();
        }
    }

    void Application::OnEvent(Event &e)
    {
        LOGI("on OnEvent {0}", e.ToString());
        EventDispatcher dispatcher(e);
        dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));
    }

    bool Application::OnWindowClose(WindowCloseEvent &e)
    {
        m_Running = false;
        return true;
    }

    void Application::PushLayer(Layers *layer)
    {
        m_LayerStack.PushLayer(layer);
        layer->OnAttach();
    }

    void Application::PushOverlay(Layers *layer)
    {
        m_LayerStack.PushOverlay(layer);
        layer->OnAttach();
    }

}