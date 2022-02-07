#include "UIText.h"

UIText::UIText(UIElement* parent, SDL_Rect size, std::string text, uint16_t textSize, TEXTFORMAT format)
	: UIElement(parent, size, text), text(text), textSize(textSize), format(format)
{
}

void UIText::drawBeta()
{
	TEXT->setFont(GETFONT("HTOWERT.TTF", textSize))->setRenderRect(this->getSize())->setTextFormat(format)->print(text);
}
