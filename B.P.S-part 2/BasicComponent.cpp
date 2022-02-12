#include "BasicComponent.h"
#include "WorkSpace.h"

BasicComponent::BasicComponent(Point position, std::string title, Type type, Uint16 inputPorts, Uint16 outputPorts, std::string luaCode) :
    pos(position), type(type), inp(inputPorts), out(outputPorts), code(luaCode)
{
}

Type BasicComponent::getType()
{
    return type;
}

Point BasicComponent::getPosition()
{
    return pos;
}

Rect BasicComponent::getSize()
{
    Rect size =
    {
        pos.x,
        pos.y,
        std::ceil(title.size() * SCALE) + 2,
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

//Port* BasicComponent::getInputPortsAt(Uint16 id)
//{
//    return inputPorts.at(id);
//}
//
//Port* BasicComponent::getOutputPortsAt(Uint16 id)
//{
//    return outputPorts.at(id);
//}

void BasicComponent::drawBody()
{
    //SDL_SetRenderDrawColor(RENDER, )
}

void BasicComponent::drawPorts()
{
}

void BasicComponent::drawText()
{
}

void BasicComponent::update()
{
}
