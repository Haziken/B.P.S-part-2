#pragma once
#include "FontLoad.h"
#include "S_Window.h"
#include <cmath>

#define TEXT TextPrint::instance()

enum class TEXTFORMAT
{
	CENTER = 0x00,
	LEFT = 0x01,
	RIGHT = 0x02,
};

enum class BORDER
{
	SOLID
};

class TextPrint
{
public:
	static TextPrint* instance();

	void print(std::string text);

	TextPrint* setForeground(Color fg);
	TextPrint* setBackground(Color bg);
	TextPrint* setPosition(Point pos);
	TextPrint* setRenderRect(Rect size);
	TextPrint* setTextFormat(TEXTFORMAT format);
	TextPrint* setFont(TTF_Font* font);
	TextPrint* setBorder(BORDER border);

private:
	Rect viewRect;
	Color fg, bg;
	TEXTFORMAT format;
	TTF_Font* font;
	TextPrint();
};

