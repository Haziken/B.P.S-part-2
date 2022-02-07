#pragma once
#include "UIElement.h"
#include "UIListElement.h"
class UIList :
    public UIElement
{
public:
    UIList(UIElement* parent, SDL_Rect size, std::string title, std::function<void(UIElement* e)> callFuck = nullptr);

    void add(UIListElement* el);
    void del(UIListElement* el);

    void addText(std::string title);

private:
    UIListElement* selected;
    std::vector<UIListElement*> content;
};

