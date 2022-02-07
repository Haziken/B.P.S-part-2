#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <SDL2/SDL.h>
#include "S_Window.h"
class UIElement
{
public:
	UIElement(UIElement* parent, SDL_Rect size, std::string title, std::function<void(UIElement* e)> callFuck = nullptr);

	void addChild(UIElement* child);
	void delChild(UIElement* child);

	void setSize(SDL_Rect newSize);
	SDL_Rect getSize();

	void setCallback(std::function<void(UIElement* e)> cbf);

	void setVisible(bool val);
	void setDragble(bool val);
	void setClickeble(bool val);

	bool isVisible();
	bool isDragble();
	bool isClickeble();

	bool hitTest(SDL_Point pos);

	virtual void Update(SDL_Event* e);
	void Draw();

	virtual void drawAlpha(); // draw body
	virtual void drawBeta(); // draw extra options
	virtual void drawGamma(); // draw interact

private:

	bool visible, dragble, clickeble;

	UIElement* parent;
	SDL_Rect size;
	std::vector<UIElement*> childs;
	std::string title;
	std::function<void(UIElement* e)> callback;
};