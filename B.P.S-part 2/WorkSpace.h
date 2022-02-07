#pragma once
#include <vector>
#include "S_Window.h"
#include "BasicComponent.h"
#include <cmath>

#define SCALE WorkSpace::getScale()

class WorkSpace
{
public:
	WorkSpace(SDL_Rect size);
	~WorkSpace();

	void addComponent(BasicComponent* component);
	void delComponent(BasicComponent* component);
	
	std::vector<BasicComponent*>* getAllComponent();
	BasicComponent* getComponentFromPosition(SDL_Point position);

	void setSpaceSize(SDL_Rect newSize);

	static int getScale();
	static void setScale(int newScale);
	static SDL_Point getSpaceShift();
	static void setSpaceShift(SDL_Point newSpaceShift);

	void draw();
	void update();
private:
	std::vector<BasicComponent*> allComponents;
	SDL_Rect size; 
	static SDL_Point spaceShift;
	static int scale;
};

