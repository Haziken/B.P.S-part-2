#pragma once
#include "UIElement.h"
class UIListElement :
    public UIElement
{
public:
    UIListElement(UIElement* parent, SDL_Rect size, std::string title, std::function<void(UIElement* e)> callFuck = nullptr);
private:
};
