#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <SDL2/SDL.h>
#include "S_Window.h"
#include <cmath>
#include "Utils.hpp"

enum class LAYOUT
{
	Horizontal,
	Vertical,
	Absolute
};

enum class ALIGN
{
	Left = 0x01,
	Right = 0x02,
	Center = 0x04,
	Top = 0x08,
	VCenter = 0x10,
	Buttom = 0x20,
	Absolute = 0x40
};

class UIElement
{
public:
	UIElement(UIElement* parent, Rect size, std::string title, std::function<void(UIElement* e)> callFuck = nullptr);
	UIElement() = delete;

	UIElement* getParent();
	std::string getTitle();

	void addChild(UIElement* child);
	void delChild(UIElement* child);

	void setClipRect(Rect newClip);
	void setViewRect(Rect newView);
	void setSize(Rect newSize);

	Rect getClip();
	Rect getView();
	Rect getSize();

	void setCallback(std::function<void(UIElement* e)> cbf);
	std::function<void(UIElement* e)> getCallback();

	void setVisible(bool val);
	void setDragble(bool val);
	void setClickeble(bool val);
	void setScrolled(bool val);
	void setFocus(bool val);

	bool isVisible();
	bool isDragble();
	bool isClickeble();
	bool isScrolled();
	bool isFocus();

	void setMargin(Rect newMargin);
	void setPadding(Rect newPadding);
	void setBorder(Rect newBorder);

	Rect getMargin();
	Rect getPadding();
	Rect getBorder();

	void setAlign(uint16_t align);
	void setLayout(LAYOUT layout);

	void setBackground(Color bg);
	void setForeground(Color fg);
	void setBorderColor(Color bd);

	Color getBackground();
	Color getForeground();
	Color getBorderColor();

	bool hitTest(Point pos);

	void UpdateLayout();
	virtual void Update(SDL_Event* e);
	void Draw();

	virtual void drawAlpha(); // draw body
	virtual void drawBeta(); // draw extra options
	virtual void drawGamma(); // draw interact

private:

	bool
		visible,  // видимость
		dragble,  // перетаскиваемая
		clickeble,// нажимаемая
		scrolled, // прокручивающаяся
		focuseble,  // фокусируемая
		focus;    // фокус на окне 

	Rect 
		margin,   // внешние отсруп
		padding,  // внутренний отступ
		border,   // граница
	    clipRect, // квадрат отберки
		viewRect, // квадрат отрисовки
		size;     // положение и зармеры элемента 

	uint16_t align; // выранвнивание  
	LAYOUT layout; // позиционирование
	UIElement* parent; 
	std::vector<UIElement*> childs;
	std::string title;
	std::function<void(UIElement* e)> callback;
	Color bg, fg, cBorder, cFocus;
};