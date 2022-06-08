#ifndef APPLICATION_H
#define APPLICATION_H

#include "Window.h"
#include <memory>

namespace CC
{

    class Application
    {
    public:
        Application();
        ~Application();

        void run();

    private:
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
    };
}

#endif