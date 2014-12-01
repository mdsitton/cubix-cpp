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

		SDL_Window* get_platform_window();
	};
}