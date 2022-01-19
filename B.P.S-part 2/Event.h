#pragma once
#include <SDL2/SDL_events.h>
#include <functional>
class Event
{
public:
	Event();

	void setKeyboardUpCallback(std::function<void(SDL_KeyboardEvent* e)> callback);
	void setKeyboardDownCallback(std::function<void(SDL_KeyboardEvent* e)> callback);

	void setMouseButtonUpCallback(std::function<void(SDL_MouseButtonEvent* e)> callback);
	void setMouseButtonDownCallback(std::function<void(SDL_MouseButtonEvent* e)> callback);
	void setMouseWheelCallback(std::function<void(SDL_MouseWheelEvent* e)> callback);
	void setMouseMotionCallback(std::function<void(SDL_MouseMotionEvent* e)> callback);

	void setWindowCallback(std::function<void(SDL_WindowEvent* e)> callback);

	void setTextInputCallback(std::function<void(SDL_TextInputEvent* e)> callback);
	void setTextEditCallback(std::function<void(SDL_TextEditingEvent* e)> callback);

	bool isExit();

	void Update();
private:
	SDL_Event* e = nullptr;

	bool exit = false;

	std::function<void(SDL_KeyboardEvent* e)> keyboardUpCB;
	std::function<void(SDL_KeyboardEvent* e)> keyboardDownCB;

	std::function<void(SDL_MouseButtonEvent* e)> mouseButtonUpCB;
	std::function<void(SDL_MouseButtonEvent* e)> mouseButtonDownCB;
	std::function<void(SDL_MouseWheelEvent* e)> mouseWheelCB;
	std::function<void(SDL_MouseMotionEvent* e)> mouseMotionCB;
	
	std::function<void(SDL_WindowEvent* e)> windowCB;

	std::function<void(SDL_TextInputEvent* e)> textInputCB;
	std::function<void(SDL_TextEditingEvent* e)> textEditCB;
};

