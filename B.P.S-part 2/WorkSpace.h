#pragma once
#include <vector>
#include "S_Window.h"
#include "BasicComponent.h"
#include <cmath>

#define SCALE WorkSpace::getScale()

class WorkSpace
{
public:
	WorkSpace(Rect size);
	~WorkSpace();

	void addComponent(BasicComponent* component);
	void delComponent(BasicComponent* component);
	
	std::vector<BasicComponent*>* getAllComponent();
	BasicComponent* getComponentFromPosition(Point position);

	void setSpaceSize(Rect newSize);

	static int getScale();
	static void setScale(int newScale);
	static Point getSpaceShift();
	static void setSpaceShift(Point newSpaceShift);

	void draw();
	void update();
private:
	std::vector<BasicComponent*> allComponents;
	Rect size; 
	static Point spaceShift;
	static int scale;
};

