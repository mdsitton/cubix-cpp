#include <iostream>

#include <GL/glew.h>

#include "window.hpp"
#include "context.hpp"
#include "events.hpp"
#include "config.hpp"

bool running = true;

bool handleEvent(CubixCore::Event event)
{
    running = false;
    return true;
}

int main()
{
    std::cout << "Hello World!\n";
    if (PLATFORM_WINDOWS) {
	std::cout << "Platform: Windows";
    }else if (PLATFORM_LINUX) {
	std::cout << "Platform: Linux";
    }else if (PLATFORM_OSX) {
	std::cout << "Platform: OS X";
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
    lis.handler = handleEvent;
    lis.mask = CubixCore::EventType::Quit;

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
