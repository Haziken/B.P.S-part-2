#include "S_Window.h"
#include "Event.h"
#include "WorkSpace.h"
#include "LuaRunner.h"
#include "UserInterface.h"
#include <iostream>

int main(int argc, char** argv)
{
	WINDOW->init("TEST", 100,100,1440,900, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE, SDL_RENDERER_ACCELERATED);
	Event* ev = new Event();
	SDL_Rect winsize;
	WorkSpace* sp = new WorkSpace({ 0,0,1440,900 });

	UserInterface* ui = new UserInterface({ 0,0,1440,900 });

	SDL_Point mousePosition;

	ev->setUIEvent([&](SDL_Event* e)
		{
			ui->Update(e);
		});

	ev->setWindowCallback([&](SDL_WindowEvent* e)
		{
			if (e->event == SDL_WINDOWEVENT_RESIZED)
			{
				sp->setSpaceSize({ 0,0, e->data1, e->data2 });
				std::cout << e->data1 << " " << e->data2 << std::endl;
			}
		});

	ev->setMouseWheelCallback([&](SDL_MouseWheelEvent* e) 
		{
			if (e->y > 0) sp->setScale(sp->getScale() * 1.5);
			if (e->y < 0) sp->setScale(sp->getScale() / 1.5);
		});

	ev->setMouseMotionCallback([&](SDL_MouseMotionEvent* e)
		{
			mousePosition = { e->x, e->y };
			//std::cout << mousePosition.x << " " << mousePosition.y << std::endl;
		});

	UIElement* el = new UIElement(ui->getParent(), { 100,100,200,200 }, "test");
	UIButton* el2 = new UIButton(el, { 10,10,50,50 }, "button", 16, [](UIElement* e) {std::cout << "BUTTON" << std::endl; });
	//UIText* text = new UIText(el, {10,10,20*14,50}, "test message", 20);

	while (!ev->isExit())
	{
		ev->Update();
		sp->draw();
		ui->Draw();

		WINDOW->update({ 0x2e, 0x2e, 0x2e, 255 });
	}

	return 0;
}
// #FFFFFF, #E3E3E3, #C7C7C7, #ACACAC, #909090, #757575, #5D5D5D, #464646, #2E2E2E, #171717, #000000