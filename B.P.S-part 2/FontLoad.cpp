#include "FontLoad.h"
#include <iostream>
FontLoad::FontLoad()
{
	TTF_Init();
}

FontLoad* FontLoad::instance()
{
	static FontLoad* fl = new FontLoad();
	return fl;
}

TTF_Font* FontLoad::getFont(std::string fontName, uint16_t fontSize)
{
	std::string fontID = fontName + std::to_string(fontSize);
	if (fontMap.find(fontID) != fontMap.end()) return fontMap[fontID];
	TTF_Font* font = TTF_OpenFont((fontDirect + "/" + fontName).c_str(), fontSize);
	if (!font) throw;
	fontMap[fontID] = font;
	return font;
}

void FontLoad::setFontPath(std::string fontPath)
{
	fontDirect = fontPath;
}
