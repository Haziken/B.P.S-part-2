#include "UIElement.h"

UIElement::UIElement(UIElement* parent, SDL_Rect size, std::string title, std::function<void(UIElement* e)> callFuck) : size(size), parent(parent), title(title), callback(callFuck)
{
	visible = true;
	dragble = true;
	clickeble = false;
	if (parent) parent->addChild(this);
}

void UIElement::addChild(UIElement* child)
{
	if (child) childs.push_back(child);
}

void UIElement::delChild(UIElement* child)
{
	for (std::vector<UIElement*>::iterator it = childs.begin(); it != childs.end(); ++it)
	{
		if (*it == child)
		{
			childs.erase(it);
			break;
		}
	}
}

void UIElement::setSize(SDL_Rect newSize)
{
	size = newSize;
}

SDL_Rect UIElement::getSize()
{
	return size;
}

void UIElement::setCallback(std::function<void(UIElement* e)> cbf)
{
	callback = cbf;
}

void UIElement::setVisible(bool val)
{
	visible = val;
}

void UIElement::setDragble(bool val)
{
	dragble = val;
}

void UIElement::setClickeble(bool val)
{
	clickeble = val;
}

bool UIElement::isVisible()
{
	return visible;
}

bool UIElement::isDragble()
{
	return dragble;
}

bool UIElement::isClickeble()
{
	return clickeble;
}

bool UIElement::hitTest(SDL_Point pos)
{
	if (!isVisible()) return false;
	return SDL_PointInRect(&pos, &size);
}

void UIElement::Update(SDL_Event* e)
{
	switch (e->type)
	{
	case SDL_MOUSEBUTTONUP:
		SDL_Point mousePos = { e->button.x, e->button.y };
		if (hitTest(mousePos))
		{
			if (isClickeble() && callback) callback(this);
		}
		break;
	}
	for (auto ch : childs) ch->Update(e);
}

void UIElement::Draw()
{
	drawAlpha();
	drawBeta();
	SDL_Rect r;
	//SDL_RenderGetViewport(RENDER, &r);
	for (auto ch : childs) ch->Draw();
	//SDL_RenderSetViewport(RENDER, &r);
	drawGamma();
}

void UIElement::drawAlpha()
{
	
}

void UIElement::drawBeta()
{
}

void UIElement::drawGamma()
{
	SDL_SetRenderDrawColor(RENDER, 0x5D, 0x5D, 0x5D, 255);
	SDL_RenderDrawRect(RENDER, &size);
}
