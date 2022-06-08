#pragma once

#include <string>
#include <functional>


namespace CC
{
    struct WindowProps
    {
        std::string Title;
        uint32_t Width;
        uint32_t Height;

        WindowProps(const std::string &title = "CC World",
                    uint32_t width = 1280, uint32_t Height = 720)
            : Title(title), Width(width), Height(Height)
        {

        }
    };

    class Window
    {
    public:

        virtual ~Window(){}
        virtual void OnUpdate() = 0;
        virtual uint32_t getWidth() const = 0;
        virtual uint32_t getHeight() const = 0;

        // using EventCallbackFn = std::function<void(OnUpdate&)>;

        // virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
        virtual void SetVSync(bool enable) = 0;
        virtual bool IsVSync() const = 0;

        static Window* Create(const WindowProps& props = WindowProps());
    };
}