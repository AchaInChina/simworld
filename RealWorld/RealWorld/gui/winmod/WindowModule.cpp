#include "WindowModule.h"
#include <stdio.h>


#ifdef WIN32
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "gui\\glew\\lib\\glew.lib")
#pragma comment(lib, "gui\\sdl\\lib\\SDL2d.lib")
#else
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "gui\\glew\\lib\\64\\glew.lib")
#pragma comment(lib, "gui\\sdl\\lib\\64\\SDL2d.lib")
#endif



WindowModule::WindowModule()
{
}


WindowModule::~WindowModule()
{
}

bool WindowModule::Init()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) /* Initialize SDL's Video subsystem */
	{
		sdldie("Unable to initialize SDL"); /* Or die on error */
		return false;
	}
		

											/* Request opengl 3.2 context.
											* SDL doesn't have the ability to choose which profile at this time of writing,
											* but it should default to the core profile */
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

	/* Turn on double buffering with a 24bit Z buffer.
	* You may need to change this to 16 or 32 for your system */
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
	return true;
}

bool WindowModule::OpenWindow(std::string name, int x, int y)
{
	/* Create our window centered at 512x512 resolution */
	m_MainWindow = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		x, y, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
	if (!m_MainWindow) /* Die if creation failed */
	{
		sdldie("Unable to create window");
	}
		

	checkSDLError(__LINE__);
	return true;
}

bool WindowModule::EnableGL()
{
	/* Create our opengl context and attach it to our window */
	m_MainContext = SDL_GL_CreateContext(m_MainWindow);
	checkSDLError(__LINE__);

	/* This makes our buffer swap syncronized with the monitor's vertical refresh */
	SDL_GL_SetSwapInterval(1);

	return true;
}

bool WindowModule::UpdateShow()
{
	SDL_GL_SwapWindow(m_MainWindow);
	return true;
}

void WindowModule::ShowDelay(int ms)
{
	SDL_Delay(ms);
}

bool WindowModule::ReleaseGL()
{
	SDL_GL_DeleteContext(m_MainContext);
	m_MainContext = nullptr;
	return true;
}

bool WindowModule::CloseWindow()
{
	SDL_DestroyWindow(m_MainWindow);
	m_MainWindow = nullptr;
	return true;
}

bool WindowModule::Release()
{
	SDL_Quit();
	return true;
}

void WindowModule::ShowRed()
{
	glClearColor(1.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
}

void WindowModule::ShowGreen()
{
	/* Same as above, but green */
	glClearColor(0.0, 1.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
}

void WindowModule::ShowBlue()
{
	/* Same as above, but blue */
	glClearColor(0.0, 0.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
}

void WindowModule::sdldie(const char *msg)
{
	printf("%s: %s\n", msg, SDL_GetError());
	SDL_Quit();
	exit(1);
}

void WindowModule::checkSDLError(int line /*= -1*/)
{
#ifndef NDEBUG
	const char *error = SDL_GetError();
	if (*error != '\0')
	{
		printf("SDL Error: %s\n", error);
		if (line != -1)
			printf(" + line: %i\n", line);
		SDL_ClearError();
	}
#endif
}
