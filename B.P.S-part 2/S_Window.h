#pragma once
#include <SDL2/SDL.h>
#include "Utils.hpp"

#define WINDOW S_Window::instanse()
#define RENDER WINDOW->getRenderer()

class S_Window
{
public:
	static S_Window* instanse();
	int init(const char* title, int x, int y, int w, int h, Uint32 window_flag, Uint32 renderer_flag);
	SDL_Window* getWindow();
	SDL_Renderer* getRenderer();
	SDL_Point getWindowSize();
	void update(Color background = {255,255,255,255});
	~S_Window();
private:
	SDL_Window* win = nullptr;
	SDL_Renderer* ren = nullptr;
	S_Window();
};

