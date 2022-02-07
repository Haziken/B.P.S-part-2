#pragma once
#include "UIElement.h"
#include "UIText.h"
#include "UIButton.h"
class UserInterface
{
public:
	UserInterface(SDL_Rect size);

	void setSize(SDL_Rect newSize);
	SDL_Rect getSize();

	UIElement* getParent();

	void Update(SDL_Event* e);
	void Draw();

private:
	UIElement* mainParent;
};

