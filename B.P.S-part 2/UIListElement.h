#pragma once
#include "UIElement.h"
class UIListElement :
    public UIElement
{
public:
    UIListElement(UIElement* parent, Rect size, std::string title, std::function<void(UIElement* e)> callFuck = nullptr);

    void setSelect(bool sel);
    void setSelectColor(Color col);
private:
    bool select;
    Color selecColor;
};

