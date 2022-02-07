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

	TextPrint* setForeground(SDL_Color fg);
	TextPrint* setBackground(SDL_Color bg);
	TextPrint* setPosition(SDL_Point pos);
	TextPrint* setRenderRect(SDL_Rect size);
	TextPrint* setTextFormat(TEXTFORMAT format);
	TextPrint* setFont(TTF_Font* font);
	TextPrint* setBorder(BORDER border);

private:
	SDL_Rect viewRect;
	SDL_Color fg, bg;
	TEXTFORMAT format;
	TTF_Font* font;
	TextPrint();
};

