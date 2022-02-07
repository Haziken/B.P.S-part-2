#include "UserInterface.h"

UserInterface::UserInterface(SDL_Rect size) : mainParent(new UIElement(nullptr, size, "mainUI"))
{
}

void UserInterface::setSize(SDL_Rect newSize)
{
	mainParent->setSize(newSize);
}

SDL_Rect UserInterface::getSize()
{
	return mainParent->getSize();
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
