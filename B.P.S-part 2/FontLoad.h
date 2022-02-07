#pragma once
#include <string>
#include <map>
#include <SDL2/SDL_ttf.h>

#define FONTLOAD FontLoad::instance()
#define GETFONT(path, size) FONTLOAD->getFont(path, size)

class FontLoad
{
public:
	static FontLoad* instance();
	TTF_Font* getFont(std::string fontName, uint16_t fontSize);
	void setFontPath(std::string fontPath);
private:
	FontLoad();
	std::string fontDirect = ".";
	std::map<std::string, TTF_Font*> fontMap;
};

