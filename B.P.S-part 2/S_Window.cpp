#include "S_Window.h"

S_Window* S_Window::instanse()
{
    static S_Window* singleSWindowPtr = new S_Window();
    return singleSWindowPtr;
}

int S_Window::init(const char* title, int x, int y, int w, int h, Uint32 window_flag, Uint32 renderer_flag)
{
    int error = 0;
    error |= SDL_Init(SDL_INIT_EVERYTHING);
    win = SDL_CreateWindow(title, x, y, w, h, window_flag);
    ren = SDL_CreateRenderer(win, -1, renderer_flag);
    return error | !win | !ren;
}

SDL_Window* S_Window::getWindow()
{
    return win;
}

SDL_Renderer* S_Window::getRenderer()
{
    return ren;
}

S_Window::~S_Window()
{
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
}

S_Window::S_Window()
{
}
