#include "WorkSpace.h"

int WorkSpace::scale = 10;
Point WorkSpace::spaceShift = { 0,0 };

WorkSpace::WorkSpace(Rect size) : size(size)
{
}

WorkSpace::~WorkSpace()
{
}

void WorkSpace::addComponent(BaseElement* component)
{
	allComponents.push_back(component);
}

void WorkSpace::delComponent(BaseElement* component)
{
	for (std::vector<BaseElement*>::iterator i = allComponents.begin(); i != allComponents.end(); ++i)
	{
		if (*i == component)
		{
			allComponents.erase(i);
			break;
		}
	}
}

std::vector<BaseElement*>* WorkSpace::getAllComponent()
{
	return &allComponents;
}

//BaseElement* WorkSpace::getComponentFromPosition(Point position)
//{
//	for (auto cmp : allComponents)
//	{
//		Rect cmp_pos = cmp->getSize();
//		cmp_pos.x = (cmp_pos.x - spaceShift.x) * scale;
//		cmp_pos.y = (cmp_pos.y - spaceShift.y) * scale;
//		cmp_pos.w *= scale;
//		cmp_pos.h *= scale;
//		if (SDL_PointInRect(&position, &cmp_pos)) return cmp;
//	}
//	return nullptr;
//}

void WorkSpace::setSpaceSize(Rect newSize)
{
	size = newSize;
}

int WorkSpace::getScale()
{
	return scale;
}

void WorkSpace::setScale(int newScale)
{
	scale = std::min(std::max(newScale, 10), 40);
}

Point WorkSpace::getSpaceShift()
{
	return spaceShift;
}

void WorkSpace::setSpaceShift(Point newSpaceShift)
{
	spaceShift = newSpaceShift;
}

void WorkSpace::draw()
{
	SDL_SetRenderDrawColor(RENDER, 0x46, 0x46, 0x46, 255); //#464646
	for (Uint16 x = size.x; x < size.x + size.w; x += scale)
	{
		for (Uint16 y = size.y; y < size.y + size.h; y += scale)
		{
			SDL_RenderDrawLine(RENDER, x, size.y, x, size.y + size.h);
			SDL_RenderDrawLine(RENDER, size.x, y, size.x + size.w, y);
		}
	}
	for (auto i : allComponents) 
		i->Draw();
}

void WorkSpace::update()
{
	/*for (auto i : allComponents) i->update();*/
}