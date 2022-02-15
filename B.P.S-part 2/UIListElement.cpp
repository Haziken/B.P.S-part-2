#include "UIListElement.h"

UIListElement::UIListElement(UIElement* parent, Rect size, std::string title, std::function<void(UIElement* e)> callFuck) :
	UIElement(parent, size, title, nullptr), select(false)
{
	setClickeble(true);
	selecColor = { 0,0,0,100 };
}

void UIListElement::setSelect(bool sel)
{
	select = sel;
	if (select)
		setBackground(selecColor);
	else
		setBackground({93,93,93,255});
}

void UIListElement::setSelectColor(Color col)
{
	selecColor = col;
}
