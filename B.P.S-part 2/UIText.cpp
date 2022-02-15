#include "UIText.h"

UIText::UIText(UIElement* parent, Rect size, std::string text, uint16_t textSize, TEXTFORMAT format)
	: UIElement(parent, size, text), text(text), textSize(textSize), format(format)
{
}

void UIText::drawBeta()
{
	Rect textRect = getView();
	textRect.x = getPadding().x + getBorder().x;
	textRect.y = getPadding().y + getBorder().y;
	textRect.w -= getPadding().w + getBorder().w;
	textRect.h -= getPadding().h + getBorder().h;
	TEXT->
		setFont(GETFONT("HTOWERT.TTF", textSize))->
		setRenderRect(textRect)->
		setTextFormat(format)->
		setForeground(getForeground())->
			print(text);
}
