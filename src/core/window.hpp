#include <string>

#include "SDL.h"

namespace CubixCore
{

	class Context {};

	class Window
	{
	private:
		std::string m_title;
		bool m_fullscreen;

		int m_width;
		int m_height;
		int m_x;
		int m_y;

		Uint32 m_sdlFlags;
		SDL_Window* m_sdlWindow;

	public:

		Window(int width=800, int height=600,
		       bool fullscreen=false, std::string title="Game");

		~Window();

		void make_current(Context* context);
		void flip();

	};

}