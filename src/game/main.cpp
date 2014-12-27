#include <iostream>

#include "window.hpp"
#include "context.hpp"
#include "config.hpp"

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

    win.make_current(&con);

    win.make_current(nullptr);
    return 0;
}
