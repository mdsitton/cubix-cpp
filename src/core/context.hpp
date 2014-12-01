#include "SDL.h"

namespace CubixCore
{
	class Window;

	class Context
	{
	private:
		int m_major;
		int m_minor;
		int m_msaa;
		int m_profile;

		Window* m_window;
		SDL_GLContext m_context;


	public:

		void set_window(window*){m_window = window;}
		SDL_GLContext get_platform_context() {return m_context;}
	};
}