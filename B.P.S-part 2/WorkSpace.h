#pragma once
#include <vector>
#include "S_Window.h"
#include "BaseElement.h"
#include <cmath>

#define SCALE WorkSpace::getScale()

class WorkSpace
{
public:
	WorkSpace(Rect size);
	~WorkSpace();

	void addComponent(BaseElement* component);
	void delComponent(BaseElement* component);
	
	std::vector<BaseElement*>* getAllComponent();
	BaseElement* getComponentFromPosition(Point position);

	void setSpaceSize(Rect newSize);

	static int getScale();
	static void setScale(int newScale);
	static Point getSpaceShift();
	static void setSpaceShift(Point newSpaceShift);

	void draw();
	void update();
private:
	std::vector<BaseElement*> allComponents;
	Rect size; 
	static Point spaceShift;
	static int scale;
};

