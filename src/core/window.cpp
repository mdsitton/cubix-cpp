#include "window.hpp"

namespace CubixCore
{

	Window::Window(int width, int height, bool fullscreen, std::string title)
	: m_width(width), m_height(height), m_fullscreen(fullscreen), m_title(title)
	{
		// Implementation
	}

	void Window::make_current(Context* context)
	{
		//Implementation
	}

	void Window::flip()
	{
		// Implementation
	}
}