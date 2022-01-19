#include "Event.h"

Event::Event()
{
	e = new SDL_Event();
}

void Event::setKeyboardUpCallback(std::function<void(SDL_KeyboardEvent* e)> callback)
{
	keyboardUpCB = callback;
}

void Event::setKeyboardDownCallback(std::function<void(SDL_KeyboardEvent* e)> callback)
{
	keyboardDownCB = callback;
}

void Event::setMouseButtonUpCallback(std::function<void(SDL_MouseButtonEvent* e)> callback)
{
	mouseButtonUpCB = callback;
}

void Event::setMouseButtonDownCallback(std::function<void(SDL_MouseButtonEvent* e)> callback)
{
	mouseButtonDownCB = callback;
}

void Event::setMouseWheelCallback(std::function<void(SDL_MouseWheelEvent* e)> callback)
{
	mouseWheelCB = callback;
}

void Event::setMouseMotionCallback(std::function<void(SDL_MouseMotionEvent* e)> callback)
{
	mouseMotionCB = callback;
}

void Event::setWindowCallback(std::function<void(SDL_WindowEvent* e)> callback)
{
	windowCB = callback;
}

void Event::setTextInputCallback(std::function<void(SDL_TextInputEvent* e)> callback)
{
	textInputCB = callback;
}

void Event::setTextEditCallback(std::function<void(SDL_TextEditingEvent* e)> callback)
{
	textEditCB = callback;
}

bool Event::isExit()
{
	return exit;
}

void Event::Update()
{
	while (SDL_PollEvent(e))
	{
		if (e->type == SDL_QUIT) exit = true;

		if (e->type == SDL_KEYDOWN && keyboardDownCB) keyboardDownCB(&e->key);
		if (e->type == SDL_KEYUP && keyboardUpCB) keyboardUpCB(&e->key);

		if (e->type == SDL_MOUSEBUTTONDOWN && mouseButtonDownCB) mouseButtonDownCB(&e->button);
		if (e->type == SDL_MOUSEBUTTONUP && mouseButtonUpCB) mouseButtonUpCB(&e->button);
		if (e->type == SDL_MOUSEWHEEL && mouseWheelCB) mouseWheelCB(&e->wheel);
		if (e->type == SDL_MOUSEMOTION && mouseMotionCB) mouseMotionCB(&e->motion);

		if (e->type == SDL_WINDOWEVENT && windowCB) windowCB(&e->window);

		if (e->type == SDL_TEXTINPUT && textInputCB) textInputCB(&e->text);
		if (e->type == SDL_TEXTEDITING && textEditCB) textEditCB(&e->edit);
	}
}
