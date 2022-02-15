#include "UIList.h"

UIList::UIList(UIElement* parent, Rect size, std::string title, std::function<void(UIElement* e)> callFuck) : 
	UIElement(parent, size, title, callFuck)
{
	selected = nullptr;

	content_view = new UIElement(this, {0,0,-1,-1}, "CONTENT");
	content_view->setLayout(LAYOUT::Vertical);
	content_view->setScrolled(true);
	selectColor = { 0,0,0,100 };
}

UIElement* UIList::getSelected()
{
	return selected;
}

void UIList::setSelectColor(Color sc)
{
	selectColor = sc;
	for (auto it : content) it->setSelectColor(selectColor);
}

Color UIList::getSelectColor()
{
	return selectColor;
}

void UIList::add(UIListElement* el)
{
	content.push_back(el);
	content_view->addChild(el);
	el->setCallback([=](UIElement* e)
		{
			UIListElement* el = (UIListElement*)e;
			for (auto it = content.begin(); it != content.end(); ++it)
			{
				UIListElement* c = *it;
				if (c == el)
				{
					selected = c;
					c->setSelect(true);
					if (this->getCallback())
						this->getCallback()(this);
				}
				else
				{
					c->setSelect(false);
				}
			}
		});
}

void UIList::del(UIListElement* el)
{
	for (std::vector<UIListElement*>::iterator it = content.begin(); it != content.end(); ++it)
	{
		if (*it == el)
		{
			content.erase(it);
			break;
		}
	}
	UpdateLayout();
}

void UIList::addText(std::string title)
{
	UIListElement* newEl = new UIListElement(nullptr, { 0,0,-1,20 }, title);
	newEl->setSelectColor(selectColor);
	newEl->setBorder({ 1,1,1,1 });
	UIText* text = new UIText(newEl, { 0,0,-1,-1 }, title, 20);
	text->setBackground({0,0,0,0});
	add(newEl);
}
