#include "S_Window.h"
#include "Event.h"

int main(int argc, char** argv)
{
	WINDOW->init("TEST", 100,100,500,500, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE, SDL_RENDERER_ACCELERATED);
	Event* ev = new Event();

	while (!ev->isExit())
	{
		ev->Update();
	}

	return 0;
}