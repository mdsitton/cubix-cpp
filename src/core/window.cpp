#include "window.hpp"

namespace CubixCore
{

	Window::Window(int width, int height, bool fullscreen, std::string title)
	: m_width(width), m_height(height), m_fullscreen(fullscreen), m_title(title)
	{
		m_sdlFlags = defaultWindowFlag;
		m_sdlWindow = SDL_CreateWindow(self.title, m_x, m_y, m_width, m_height, m_sdlFlags)
		m_context = nullptr;
	}

	void Window::make_current(Context* context)
	{

		if (context != nullptr) {
			context->set_window(this);
			m_context = context;
			SDL_GL_MakeCurrent(window, context);
		}
	}

	void Window::flip()
	{
		// Implementation
	}
}