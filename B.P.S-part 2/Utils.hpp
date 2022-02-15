#pragma once
typedef SDL_Rect Rect;
typedef SDL_Point Point;
typedef SDL_Color Color;

#include <SDL2/SDL.h>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <iostream>

#define SDLCOLOR(c) c.r, c.g, c.b, c.a

namespace Utils
{
	namespace mColor
	{
		// #FFFFFF, #E3E3E3, #C7C7C7, #ACACAC, #909090, #757575, #5D5D5D, #464646, #2E2E2E, #171717, #000000
		const Color red = { 255,0,0,255 };
		const Color green = { 0,255,0,255 };
		const Color blue = { 0,0,255,255 };
		const Color white = { 255,255,255,255 };
		const Color black = { 0,0,0,255 };
		
		inline Color HexToColor(std::string hex)
		{
			return
			{
				(unsigned char)std::stoi(hex.substr(1,2), 0, 16),
				(unsigned char)std::stoi(hex.substr(3,2), 0, 16),
				(unsigned char)std::stoi(hex.substr(5,2), 0, 16),
				(unsigned char)(hex.size() == 9 ? std::stoi(hex.substr(7,2), 0 , 16) : 255)
			};
		}
		inline Color SetAlpha(Color c, Uint8 alpha)
		{
			c.a = alpha;  return c;
		}
		
		const Color gray1 = HexToColor("#171717");
		const Color gray2 = HexToColor("#2E2E2E");
		const Color gray3 = HexToColor("#464646");
		const Color gray4 = HexToColor("#5D5D5D");
		const Color gray5 = HexToColor("#757575");
		const Color gray6 = HexToColor("#909090");
		const Color gray7 = HexToColor("#ACACAC");
		const Color gray8 = HexToColor("#C7C7C7");
		const Color gray9 = HexToColor("#E3E3E3");
	}

	inline void DrawLine(SDL_Renderer* renderer, int x, int y, int x1, int y1, int depth)
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

	inline void DrawCircle(SDL_Renderer* renderer, int x, int y, int radius, bool fill = false)
	{
		while (radius > 0)
		{
			for (int i = 0; i < 360; i++)
			{
				SDL_RenderDrawPoint(renderer, x + radius * cos(i), y + radius * sin(i));
			}
			if (!fill) break;
			radius--;
		}
	}

	inline void DrawTriangle(SDL_Renderer* renderer, int x, int y, int w, int h)
	{
		SDL_RenderDrawLine(renderer, x, y, x, y + h);
		SDL_RenderDrawLine(renderer, x, y, x + w, y + h / 2);
		SDL_RenderDrawLine(renderer, x, y + h, x + w, y + h / 2);
	}

	inline void SetRenderColor(SDL_Renderer* renderer, Color c)
	{
		SDL_SetRenderDrawColor(renderer, SDLCOLOR(c));
	}
}
inline std::ostream& operator<<(std::ostream& out, const Color& c)
{
	out << "Red: " << (unsigned short int)c.r << ", Green: " << (unsigned short int)c.g << ", Blue: " << (unsigned short int)c.b;
	return out;
}

inline std::ostream& operator<<(std::ostream& out, const Rect& r)
{
	out << "Rect x: " << r.x << ", y: " << r.y << ", w: " << r.w << ", h: " << r.h;
	return out;
}

inline std::ostream& operator<<(std::ostream& out, const Point& p)
{
	out << "Point x: " << p.x << ", y: " << p.y;
	return out;
}