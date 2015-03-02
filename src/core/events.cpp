#include "events.hpp"

#include <algorithm>
#include <iostream>

namespace CubixCore
{

    Events::Events()
    {
        SDL_InitSubSystem(SDL_INIT_EVENTS);
    }

    void Events::add_listener(Listener &listener)
    {
        static int id {0};

        id++;
        listener.id = id;

        m_listeners.push_back(&listener);

    }

    void Events::remove_listener(Listener &listener)
    {
        auto vecEnd = std::end(m_listeners);
        auto vecLoc = std::find(std::begin(m_listeners), vecEnd, &listener);

        if (vecLoc != vecEnd) {
            m_listeners.erase(vecLoc);
        }

    }

    void Events::broadcast_event(Event &event)
    {
        for (Listener *listener : m_listeners) {
            if ((listener->mask & event.type) != EventType::EventNone) {
                listener->handler(event);
            }
        }

    }

    void Events::process()
    {
        SDL_Event sdlevent;
        bool eventProcessed = false;

        while (SDL_PollEvent(&sdlevent)) {
            if (sdlevent.type == SDL_QUIT) {
                QuitEvent event {true};

                m_event.type = EventType::Quit;
                m_event.time = 0.0;                    // not used currently
                m_event.event.quit = event;

                eventProcessed = true;
            }

            if (eventProcessed == true) {
                broadcast_event(m_event);
            }

        }

    }

}