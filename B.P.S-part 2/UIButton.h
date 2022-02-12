#pragma once
#include "UIText.h"
#include <functional>
class UIButton :
    public UIText
{
public:
    UIButton(UIElement* parent, Rect size, std::string text, uint16_t textSize, std::function<void(UIElement* e)> callfunc);
private:
};

