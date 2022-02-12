#include "UserInterface.h"

UserInterface::UserInterface(Rect size) : mainParent(new UIElement(nullptr, size, "mainUI"))
{
}

void UserInterface::setSize(Rect newSize)
{
	mainParent->setViewRect(newSize);
}

Rect UserInterface::getSize()
{
	return mainParent->getView();
}

UIElement* UserInterface::getParent()
{
	return mainParent;
}

void UserInterface::Update(SDL_Event* e)
{
	mainParent->Update(e);
}

void UserInterface::Draw()
{
	mainParent->Draw();
}
