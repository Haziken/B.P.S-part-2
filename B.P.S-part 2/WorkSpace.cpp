#include "WorkSpace.h"

int WorkSpace::scale = 10;
SDL_Point WorkSpace::spaceShift = { 0,0 };

WorkSpace::WorkSpace(SDL_Rect size) : size(size)
{
}

WorkSpace::~WorkSpace()
{
}

void WorkSpace::addComponent(BasicComponent* component)
{
	allComponents.push_back(component);
}

void WorkSpace::delComponent(BasicComponent* component)
{
	for (std::vector<BasicComponent*>::iterator i = allComponents.begin(); i != allComponents.end(); ++i)
	{
		if (*i == component)
		{
			allComponents.erase(i);
			break;
		}
	}
}

std::vector<BasicComponent*>* WorkSpace::getAllComponent()
{
	return &allComponents;
}

BasicComponent* WorkSpace::getComponentFromPosition(SDL_Point position)
{
	for (auto cmp : allComponents)
	{
		SDL_Rect cmp_pos = cmp->getSize();
		cmp_pos.x = (cmp_pos.x - spaceShift.x) * scale;
		cmp_pos.y = (cmp_pos.y - spaceShift.y) * scale;
		cmp_pos.w *= scale;
		cmp_pos.h *= scale;
		if (SDL_PointInRect(&position, &cmp_pos)) return cmp;
	}
	return nullptr;
}

int WorkSpace::getScale()
{
	return scale;
}

void WorkSpace::setScale(int newScale)
{
	if (newScale < 10) throw;
	scale = newScale;
}

SDL_Point WorkSpace::getSpaceShift()
{
	return spaceShift;
}

void WorkSpace::setSpaceShift(SDL_Point newSpaceShift)
{
	spaceShift = newSpaceShift;
}

void WorkSpace::draw()
{
	SDL_SetRenderDrawColor(RENDER, 50,50,50,50);
	for (Uint16 x = size.x; x < size.x + size.w; x += scale)
	{
		for (Uint16 y = size.y; y < size.y + size.h; y += scale)
		{
			SDL_RenderDrawLine(RENDER, x, size.y, x, size.y + size.h);
			SDL_RenderDrawLine(RENDER, size.x, y, size.x + size.w, y);
		}
	}
	for (auto i : allComponents) i->draw();
}

void WorkSpace::update()
{
	for (auto i : allComponents) i->update();
}
