#include <iostream>

#include <GL/glew.h>

#include "window.hpp"
#include "context.hpp"
#include "events.hpp"
#include "config.hpp"

bool running = true;

bool handleEvents(CubixCore::Event &event)
{
    CubixCore::EventType type = event.type;
    switch(type) {
        case CubixCore::EventType::Quit:
            running = false;
            break;
        case CubixCore::EventType::WindowSized:
            std::cout << event.event.windowSized.width  << " "
                      << event.event.windowSized.height << " "
                      << event.event.windowSized.id     << std::endl;
            break;

    }
    return true;
}

int main()
{
    std::cout << "Game started!\n";
    if (IF_WINDOWS) {
	   std::cout << "Platform: Windows" << std::endl;
    }else if (IF_LINUX) {
	   std::cout << "Platform: Linux" << std::endl;
    }else if (IF_OSX) {
	   std::cout << "Platform: OS X" << std::endl;
    }

    CubixCore::Window win;
    CubixCore::Context con(3, 3, 0);
    CubixCore::Events eve;

    win.make_current(&con);

    GLenum err = glewInit();
    if (GLEW_OK != err)
    {
        std::cout << "Error: %s\n", glewGetErrorString(err);
    }

    CubixCore::Listener lis;
    lis.handler = handleEvents;
    lis.mask = CubixCore::EventType::Quit | CubixCore::EventType::WindowSized;

    eve.add_listener(lis);

    while (running) {
        //std::cout << "cow";
        eve.process();
        glClearColor(0.5, 0.5, 0.5, 1.0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        win.flip();
    }



    win.make_current(nullptr);
    return 0;
}
