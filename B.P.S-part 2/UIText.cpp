#include "UIText.h"

UIText::UIText(UIElement* parent, Rect size, std::string text, uint16_t textSize, TEXTFORMAT format)
	: UIElement(parent, size, text), text(text), textSize(textSize), format(format)
{
}

void UIText::drawBeta()
{
	Rect textRect = getView();
	textRect.x = 0;
	textRect.y = 0;
	TEXT->
		setFont(GETFONT("HTOWERT.TTF", textSize))->
		setRenderRect(textRect)->
		setTextFormat(format)->
		setForeground(getForeground())->
			print(text);
}
