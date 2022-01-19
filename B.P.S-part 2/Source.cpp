#include "S_Window.h"
#include "Event.h"
#include "WorkSpace.h"

int main(int argc, char** argv)
{
	WINDOW->init("TEST", 100,100,500,500, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE, SDL_RENDERER_ACCELERATED);
	Event* ev = new Event();
	WorkSpace* sp = new WorkSpace({ 0,0,500,500 });



	while (!ev->isExit())
	{
		ev->Update();

		sp->draw();

		WINDOW->update({ 255,255,255,255 });
	}

	return 0;
}