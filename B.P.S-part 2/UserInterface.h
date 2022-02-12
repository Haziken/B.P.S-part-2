#pragma once
#include "UIElement.h"
#include "UIText.h"
#include "UIButton.h"
class UserInterface
{
public:
	UserInterface(Rect size);

	void setSize(Rect newSize);
	Rect getSize();

	UIElement* getParent();

	void Update(SDL_Event* e);
	void Draw();

private:
	UIElement* mainParent;
};

