#pragma once

#include "../sdl/include/SDL.h"
#include "../glew/include/glew.h"

#include <string>


class WindowModule
{
public:
	WindowModule();
	~WindowModule();

	bool Init();

	bool OpenWindow(std::string name, int x, int y);

	bool EnableGL();

	bool UpdateShow();

	void ShowDelay(int ms);

	bool ReleaseGL();

	bool CloseWindow();

	bool Release();

	void ShowRed();
	void ShowGreen();
	void ShowBlue();

	/* A simple function that prints a message, the error code returned by SDL,
	* and quits the application */
	void sdldie(const char *msg);

	void checkSDLError(int line = -1);
private:
	SDL_Window* m_MainWindow; /* Our window handle */
	SDL_GLContext m_MainContext; /* Our opengl context handle */
};

