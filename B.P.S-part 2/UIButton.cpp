#include "UIButton.h"

UIButton::UIButton(UIElement* parent, Rect size, std::string text, uint16_t textSize, std::function<void(UIElement* e)> callfunc) :
	UIText(parent, size, text, textSize)
{
	setClickeble(true);
	setDragble(false);
	setCallback(callfunc);
}