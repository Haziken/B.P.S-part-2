#include "UIList.h"

UIList::UIList(UIElement* parent, SDL_Rect size, std::string title, std::function<void(UIElement* e)> callFuck) : 
	UIElement(parent, size, title, callFuck)
{
	selected = nullptr;
}

void UIList::add(UIListElement* el)
{
	content.push_back(el);
}

void UIList::del(UIListElement* el)
{
}

void UIList::addText(std::string title)
{
}
