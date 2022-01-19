#include "BasicComponent.h"
#include "WorkSpace.h"

BasicComponent::BasicComponent(SDL_Point position, std::string title, Type type, Uint16 inputPorts, Uint16 outputPorts, std::string luaCode) :
    pos(position), type(type), inp(inputPorts), out(outputPorts), code(luaCode)
{
}

Type BasicComponent::getType()
{
    return type;
}

SDL_Point BasicComponent::getPosition()
{
    return pos;
}

SDL_Rect BasicComponent::getSize()
{
    SDL_Rect size =
    {
        pos.x,
        pos.y,
        std::ceil(title.size() / (float)SCALE) + 2,
        std::max(inp, out) + 3
    };
    return size;
}

Uint16 BasicComponent::getInputPorts()
{
    return inp;
}

Uint16 BasicComponent::getOutputPorts()
{
    return out;
}

std::string BasicComponent::getLuaCode()
{
    return code;
}

void BasicComponent::draw()
{
}

void BasicComponent::update()
{
}
