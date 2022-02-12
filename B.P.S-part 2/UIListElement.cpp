#include "UIListElement.h"

UIListElement::UIListElement(UIElement* parent, Rect size, std::string title, std::function<void(UIElement* e)> callFuck) :
	UIElement(parent, size, title, nullptr), select(false)
{
	setClickeble(true);
}

void UIListElement::setSelect(bool sel)
{
	select = sel;
}
