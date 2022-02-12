#include <SDL2/SDL.h>
#include <sstream>
#include <string>
#include <iostream>
typedef SDL_Rect Rect;
typedef SDL_Point Point;
typedef SDL_Color Color;

#define SDLCOLOR(c) c.r, c.g, c.b, c.a

namespace COLOR
{
// #FFFFFF, #E3E3E3, #C7C7C7, #ACACAC, #909090, #757575, #5D5D5D, #464646, #2E2E2E, #171717, #000000
	const Color red = { 255,0,0,255 };
	const Color green = { 0,255,0,255 };
	const Color blue = { 0,0,255,255 };
	const Color white = { 255,255,255,255 };
	const Color black = { 0,0,0,255 };
	Color HexToColor(std::string hex)
	{		
		return 
		{ 
			(unsigned char)std::stoi(hex.substr(1,2), 0, 16),
			(unsigned char)std::stoi(hex.substr(3,2), 0, 16),
			(unsigned char)std::stoi(hex.substr(5,2), 0, 16),
			255
		};
	}
	Color SetAlpha(Color c, Uint8 alpha) 
	{ c.a = alpha;  return c; }
}

std::ostream& operator<<(std::ostream& out, const Color &c)
{
	out << "Red: " << (unsigned short int)c.r << ", Green: " << (unsigned short int)c.g << ", Blue: " << (unsigned short int)c.b;
	return out;
}

std::ostream& operator<<(std::ostream& out, const Rect& r)
{
	out << "x: " << r.x << ", y: " << r.y << ", w: " << r.w << ", h: " << r.h;
	return out;
}

void DrawLine(SDL_Renderer* renderer, int x, int y, int x1, int y1, int depth)
{
	for (int i = 0; i < depth; ++i)
	{
		SDL_RenderDrawLine(renderer,
			x + (y != y1 ? i : 0),
			y + (x != x1 ? i : 0),
			x1 + (y != y1 ? i : 0),
			y1 + (x != x1 ? i : 0));
	}
}