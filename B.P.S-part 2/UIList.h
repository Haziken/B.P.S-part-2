#pragma once
#include "UIElement.h"
#include "UIListElement.h"
#include "UIText.h"
class UIList :
    public UIElement
{
public:
    UIList(UIElement* parent, Rect size, std::string title, std::function<void(UIElement* e)> callFuck = nullptr);

    UIElement* getSelected();

    void setSelectColor(Color sc);
    Color getSelectColor();

    void add(UIListElement* el);
    void del(UIListElement* el);

    void addText(std::string title);

private:
    UIElement* content_view;
    UIListElement* selected;
    std::vector<UIListElement*> content;
    Color selectColor;
};

