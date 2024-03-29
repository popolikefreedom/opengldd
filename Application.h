#ifndef APPLICATION_H
#define APPLICATION_H

#include "Window.h"
#include <memory>
#include "event/Event.h"
#include "event/ApplicationEvent.h"
#include <functional>
#include "LayerStack.h"

namespace CC
{

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

    class Application
    {
    public:
        Application();
        ~Application();

        void run();
        void OnEvent(Event& e);

        bool OnWindowClose(WindowCloseEvent& e);
        static Application& Get(){return *application;}

        Window& getWindow(){return *m_Window;}

        void PushLayer(Layers* layer);
		void PushOverlay(Layers* layer);
   
    private:
        Window *m_Window;
        bool m_Running = true;

        static Application *application;
        LayerStack m_LayerStack;
    };
}

#endif