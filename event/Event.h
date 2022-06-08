#ifndef EVENT_H
#define EVENT_H

#include <functional>
#include <string>

#define BIT(x) (1 << x)

namespace CC
{
    enum class EventType
    {
        None = 0,
        WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
        AppTick, AppUpdate, AppRender,
        KeyPressed, KeyReleased,
        MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScroll
    };

    enum EventCategory
    {
        None = 0,
        EventCategoryApplication = BIT(0),
        EventCategoryInput = BIT(1),
        EventCategoryKeyBoard = BIT(2),
        EventCategoryAppMouse = BIT(3),
        EventCategoryAppMouseButton = BIT(4),
    };

}




#endif