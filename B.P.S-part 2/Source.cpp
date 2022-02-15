#include "S_Window.h"
#include "Event.h"
#include "WorkSpace.h"
#include "LuaRunner.h"
#include "UserInterface.h"
#include "UIList.h"

int main(int argc, char** argv)
{
	WINDOW->init("TEST", 100, 100, 1280, 720, SDL_WINDOW_SHOWN, SDL_RENDERER_ACCELERATED);
	Event* ev = new Event();
	Point winsize = WINDOW->getWindowSize();
	WorkSpace* sp = new WorkSpace({200,0,winsize.x - 200,winsize.y });

	UserInterface* ui = new UserInterface({ 0,0,winsize.x,winsize.y });
	std::string selectElement;
	Point mousePosition;

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
			/*if (e->y > 0) sp->setScale(sp->getScale() * 1.5);
			if (e->y < 0) sp->setScale(sp->getScale() / 1.5);*/
		});

	ev->setMouseMotionCallback([&](SDL_MouseMotionEvent* e)
		{
			mousePosition = { e->x, e->y };
			//std::cout << mousePosition.x << " " << mousePosition.y << std::endl;
		});

	ev->setMouseButtonUpCallback([&](SDL_MouseButtonEvent* e) 
		{
			if (e->button == SDL_BUTTON_LEFT)
			{
				std::cout << mousePosition << std::endl;
			}
		});

	ev->setKeyboardUpCallback([&](SDL_KeyboardEvent* e)
		{
			if (e->keysym.sym == SDLK_ESCAPE)
				ev->Quit();
		});

	UIElement* el = new UIElement(ui->getParent(), { 0,0,200,winsize.y }, "ComponentList");
	el->setLayout(LAYOUT::Vertical);

	UIText* programInfo = new UIText(el, { 0,0,-1,20 }, "Block Programmig v0.1", 20, TEXTFORMAT::LEFT);
	programInfo->setForeground(Utils::mColor::gray9);
	programInfo->setBorder({ 0,0,0,5 });
	programInfo->setPadding({ 0,0,0,2 });
	programInfo->setBorderColor(Utils::mColor::black);

	UIList* components = new UIList(el, { 0,0,-1,winsize.y - 20 - 50 }, "Components", 
		[&](UIElement* e) { selectElement = ((UIList*)e)->getSelected()->getTitle(); });
	components->setBorder({ 2,2,2,2 });
	components->addText("cin");
	components->addText("cout");
	components->addText("if");
	components->addText("while");
	components->addText("for");

	ui->getParent()->setBackground({0,0,0,0});
	ui->getParent()->UpdateLayout();

	Rect r = { 0,0,winsize.x-1,winsize.y };
	SDL_SetRenderDrawBlendMode(RENDER, SDL_BLENDMODE_BLEND);

	while (!ev->isExit())
	{
		SDL_SetRenderDrawColor(RENDER, SDLCOLOR(Utils::mColor::gray1));
		SDL_RenderClear(RENDER);
		ev->Update();
		sp->draw();
		ui->Draw();
		SDL_RenderSetViewport(RENDER, &r);
		SDL_RenderPresent(RENDER);
	}
	return 0;
}
// #FFFFFF, #E3E3E3, #C7C7C7, #ACACAC, #909090, #757575, #5D5D5D, #464646, #2E2E2E, #171717, #000000