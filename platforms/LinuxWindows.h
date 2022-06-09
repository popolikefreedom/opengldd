#ifndef LINUXWINDOWS_H
#define LINUXWINDOWS_H

#include "../Window.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace CC
{

    struct WindowData
    {
        std::string Title;
        uint32_t Width;
        uint32_t Height;
        bool VSync;

        Window::EventCallbackFn callback;
    };
    

    class LinuxWindows : public Window
    {
    public:

        LinuxWindows(const WindowProps& props);
        virtual ~LinuxWindows();

        void OnUpdate() override;
        
        uint32_t getWidth() const override { return m_Data.Width; }
        uint32_t getHeight() const override { return m_Data.Height; }

        void SetVSync(bool enable) override;
        bool IsVSync() const override;

        void* GetNativeWindow() const {return m_Window;};
        void SetEventCallback(const EventCallbackFn& callback) override;

    private:
        void Init(const WindowProps& props);
        void shutDown();

        GLFWwindow *m_Window;
        WindowData m_Data;
    };

}
#endif