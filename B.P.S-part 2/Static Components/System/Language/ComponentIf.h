#pragma once
#include "../../../BasicComponent.h"
class ComponentIf :
    public BasicComponent
{
public:
    ComponentIf(SDL_Point pos);

    void drawBody() override;
    void drawPorts() override;
    void drawText() override;
    void update() override;
private:
};

