#include "UIElement.h"

UIElement::UIElement(UIElement* parent, Rect size, std::string title, std::function<void(UIElement* e)> callFuck) : size(size), parent(parent), title(title), callback(callFuck)
{
	visible = true;
	dragble = true;
	clickeble = false;
	scrolled = false;
	focuseble = false;
	focus = false;
	layout = LAYOUT::Absolute;
	align = (uint16_t)ALIGN::Absolute;
	border = { 0,0,0,0 };
	margin = { 0,0,0,0 };
	padding = { 0,0,0,0 };
	viewRect = size;
	bg = { 0x5D, 0x5D, 0x5D, 255 };
	fg = { 0,0,0,0 };
	cBorder = { 0,0,0,100 };
	cFocus = Utils::mColor::SetAlpha(Utils::mColor::white, 50);
	clipRect = { 0,0,size.w, size.h };
	if (parent) parent->addChild(this);
}

void UIElement::addChild(UIElement* child)
{
	if (child) childs.push_back(child);
}

UIElement* UIElement::getParent()
{
	return parent;
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

std::string UIElement::getTitle()
{
	return title;
}

void UIElement::setClipRect(Rect newClip)
{
	clipRect = newClip;
}

void UIElement::setViewRect(Rect newView)
{
	viewRect = newView;
}

void UIElement::setSize(Rect newSize)
{
	size = newSize;
	UpdateLayout();
}

Rect UIElement::getView()
{
	return viewRect;
}

Rect UIElement::getClip()
{
	return clipRect;
}

Rect UIElement::getSize()
{
	return size;
}

void UIElement::setCallback(std::function<void(UIElement* e)> cbf)
{
	callback = cbf;
}

std::function<void(UIElement* e)> UIElement::getCallback()
{
	return callback;
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

void UIElement::setScrolled(bool val)
{
	scrolled = val;
}

void UIElement::setFocus(bool val)
{
	focus = val;
}

bool UIElement::isScrolled()
{
	return scrolled;
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

bool UIElement::isFocus()
{
	return focus;
}

void UIElement::setMargin(Rect newMargin)
{
	margin = newMargin;
	UpdateLayout();
}

void UIElement::setPadding(Rect newPadding)
{
	padding = newPadding;
	UpdateLayout();
}

void UIElement::setBorder(Rect newBorder)
{
	border = newBorder;
	UpdateLayout();
}

Rect UIElement::getMargin()
{
	return margin;
}

Rect UIElement::getPadding()
{
	return padding;
}

Rect UIElement::getBorder()
{
	return border;
}

void UIElement::setAlign(uint16_t align)
{
	this->align = align;
	UpdateLayout();
}

void UIElement::setLayout(LAYOUT layout)
{
	this->layout = layout;
	UpdateLayout();
}

void UIElement::setBackground(Color bg)
{
	this->bg = bg;
}

void UIElement::setForeground(Color fg)
{
	this->fg = fg;
}

void UIElement::setBorderColor(Color bd)
{
	cBorder = bd;
}

Color UIElement::getBackground()
{
	return bg;
}

Color UIElement::getForeground()
{
	return fg;
}

Color UIElement::getBorderColor()
{
	return cBorder;
}

bool UIElement::hitTest(Point pos)
{
	if (!isVisible()) return false;
	return SDL_PointInRect(&pos, &viewRect);
}

void UIElement::UpdateLayout()
{
	uint16_t y = 0;
	for (auto it = childs.begin(); it != childs.end(); ++it)
	{
		UIElement* child = *it;

		Rect child_margin = child->getMargin();
		Rect child_size = child->getSize();
		Rect child_border = child->getBorder();
		switch (layout)
		{
		case LAYOUT::Horizontal:
			break;
		case LAYOUT::Vertical:
		{
			y += padding.y;
			Rect childView = 
			{ 
				viewRect.x + child_size.x + child_margin.x,
				viewRect.y + child_size.y + child_margin.y + y,
				child_size.w + child_border.w,
				child_size.h + child_border.h
			};

			if(child_size.w == -1)
				childView.w = viewRect.w - child_margin.x - child_margin.w;
			if(child_size.h == -1)
				childView.h = viewRect.h - child_margin.y - child_margin.h;

			y += childView.h + child_margin.h + child_margin.y; // padding - border

			child->setViewRect(childView);
			break;
		}
		case LAYOUT::Absolute:
		{
			Rect childView = 
			{
				viewRect.x + child_size.x + child_margin.x,
				viewRect.y + child_size.y + child_margin.y,
				std::min(viewRect.w - padding.w - child_margin.w - padding.x - child_margin.x, child_size.w),
				std::min(viewRect.h - padding.h - child_margin.h - padding.y - child_margin.y, child_size.h)
			};

			if (child_size.w == -1)
				childView.w = viewRect.w - child_margin.w - child_margin.x;
			if (child_size.h == -1)
				childView.h = viewRect.h - child_margin.h - child_margin.y;

			child->setViewRect(childView);

			break;
		}
		}

		child->UpdateLayout();
	}
}

void UIElement::Update(SDL_Event* e)
{
	switch (e->type)
	{
	case SDL_MOUSEBUTTONUP:
		Point mousePos = { e->button.x, e->button.y };
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
	Rect r, c;
	SDL_RenderGetViewport(RENDER, &r);
	SDL_RenderGetClipRect(RENDER, &c);
	for (auto ch : childs) ch->Draw();
	SDL_RenderSetViewport(RENDER, &r);
	SDL_RenderSetClipRect(RENDER, &c);
	drawGamma();
}

void UIElement::drawAlpha()
{
	if (!isVisible()) return;
	SDL_RenderSetViewport(RENDER, &viewRect);

	/*if (parent)
	{
		Rect pclip = parent->getClip();
		pclip.x -= viewRect.x;
		pclip.y -= viewRect.y;
		Rect t = { 0,0,viewRect.w, viewRect.h };
		SDL_IntersectRect(&t, &pclip, &clipRect);
		clipRect = t;
		if (clipRect.w < 0)
			clipRect.w = 0;
		if (clipRect.h < 0)
			clipRect.h = 0;
	}
	else
	{
		clipRect = { 0,0,viewRect.w, viewRect.h };
	}
	SDL_RenderSetClipRect(RENDER, &clipRect);*/

	SDL_SetRenderDrawColor(RENDER, SDLCOLOR(bg));
	Rect r = { 0,0,viewRect.w, viewRect.h };
	SDL_RenderFillRect(RENDER, &r);
	
}

void UIElement::drawBeta()
{
	
}

void UIElement::drawGamma()
{
	if (!isVisible()) return;
	SDL_RenderSetViewport(RENDER, &viewRect);
	SDL_SetRenderDrawColor(RENDER, SDLCOLOR(cBorder));
	Utils::DrawLine(RENDER, 0, 0, viewRect.w, 0, border.x); // top
	Utils::DrawLine(RENDER, 0, 0, 0, viewRect.h, border.y); // left
	Utils::DrawLine(RENDER, 0, viewRect.h - border.h, viewRect.w, viewRect.h - border.h, border.h); // bottom
	Utils::DrawLine(RENDER, viewRect.w - border.w, 0, viewRect.w - border.w, viewRect.h, border.w); // right
}