#pragma once
#include <string>
#include "UIElement.h"
#include "TextPrint.h"
#include "FontLoad.h"
class UIText : public UIElement
{
public:
	UIText(UIElement* parent, Rect size, std::string text, uint16_t textSize, TEXTFORMAT format = TEXTFORMAT::CENTER);

	virtual void drawBeta() override;

private:
	std::string text;
	uint16_t textSize;
	TEXTFORMAT format;
};

