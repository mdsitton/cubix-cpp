#pragma once
#include <functional>
#include <vector>
#include <type_traits>

#include "SDL.h"

#include "keycode.hpp"

namespace CubixCore
{
    enum class EventType
    {
        EventNone    = 0,
        MouseMove    = 1 << 0,
        WindowClose  = 1 << 1,
        WindowSized  = 1 << 2,
        KeyUp        = 1 << 3,
        KeyDown      = 1 << 4,
        Quit         = 1 << 5,
    };

    using underlying = std::underlying_type<EventType>::type;

    static EventType operator|(const EventType& left, const EventType& right)
    {
        return static_cast<EventType>(static_cast<underlying>(left) | static_cast<underlying>(right));
    }

    static EventType operator&(const EventType& left, const EventType& right)
    {
        return static_cast<EventType>(static_cast<underlying>(left) & static_cast<underlying>(right));
    }


    // enable the use of bitwise operators on flags

    struct MouseMoveEvent
    {
        float x;
        float y;

        float dx;
        float dy;
    };

    struct WindowSizedEvent
    {
        int width;
        int height;

        int x;
        int y;
    };

    struct KeyUpEvent
    {
        KeyCode key;
        ModFlag mod;

    };

    struct KeyDownEvent
    {
        KeyCode key;
        ModFlag mod;

    };

    struct QuitEvent
    {
        bool quit;

    };

    union EventMan
    {
        MouseMoveEvent mouseMove;
        WindowSizedEvent windowSized;
        KeyUpEvent keyUp;
        KeyDownEvent keyDown;
        QuitEvent quit;
    };

    struct Event
    {
        EventType type;
        float time;
        EventMan event;

    };

    struct Listener
    {
        int id;
        EventType mask;
        std::function<bool (Event&)> handler;
        // more to come
    };

    class Events
    {
    private:
        std::vector<Listener*> m_listeners;
        Event m_event;
    public:
        Events();
        void add_listener(Listener &listener);
        void remove_listener(Listener &listener);
        void broadcast_event(Event &event);
        void process();
    };
}