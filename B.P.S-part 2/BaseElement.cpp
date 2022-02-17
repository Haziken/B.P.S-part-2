#include "BaseElement.h"
bool operator&(SIGNALS s0, SIGNALS s1) { return (int)(s0) & (int)(s1); };

BaseElement::BaseElement(Point pos, std::string title, SIGNALS signals, std::vector<Port*> inpPorts, std::vector<Port*> outPorts) :
	pos(pos), title(title), sig(signals), inpPorts(inpPorts), outPorts(outPorts)
{
}

std::vector<Port*>* BaseElement::getInputPorts()
{
	return &inpPorts;
}

std::vector<Port*>* BaseElement::getOutputPorts()
{
	return &outPorts;
}

void BaseElement::addInputPort(Port* p)
{
	inpPorts.push_back(p);
}

void BaseElement::addOutputPort(Port* p)
{
	outPorts.push_back(p);
}

std::string BaseElement::getTitle()
{
	return title;
}

SIGNALS BaseElement::getSignal()
{
	return sig;
}

void BaseElement::Draw()
{
	Utils::SetRenderColor(RENDER, Utils::mColor::gray6);
	Rect r = { pos.x, pos.y, (int)title.size() * 20 + 20, std::max(inpPorts.size(), outPorts.size()) * 10 + 30};
	SDL_RenderFillRect(RENDER, &r);
	r.h = 20;
	TEXT->setFont(GETFONT("HTOWERT.TTF", 20))->
		setForeground(Utils::mColor::white)->
		setRenderRect(r)->setTextFormat(TEXTFORMAT::CENTER)->print(title);
	
	Utils::SetRenderColor(RENDER, Utils::mColor::green);
	if (sig & SIGNALS::INPUT)
	{
		Utils::DrawTriangle(RENDER, r.x + 5, r.y + 5, 10, 10);
	}
	if (sig & SIGNALS::OUTPUT)
	{
		Utils::DrawTriangle(RENDER, r.x + r.w - 15, r.y + 5, 10, 10);
	}

	Utils::SetRenderColor(RENDER, Utils::mColor::blue);
	r.h = 30;
	TEXT->setFont(GETFONT("HTOWERT.TTF", 12));
	for (int i = 0; i < inpPorts.size(); ++i)
	{
		r.h += i * 10;
		Port* p = inpPorts.at(i);
		TEXT->setRenderRect({r.x + 20, r.y + r.h - 5, r.w - 20, 10})->setTextFormat(TEXTFORMAT::LEFT)->print(p->getName());
		Utils::DrawCircle(RENDER, r.x + 10, r.y + r.h, 4, p->isConnect());
	}
	
	r.h = 30;
	for (int i = 0; i < outPorts.size(); ++i)
	{
		r.h += i * 10;
		Port* p = outPorts.at(i);
		TEXT->setRenderRect({ r.x + 20, r.y + r.h - 6, r.w - 40, 10 })->setTextFormat(TEXTFORMAT::RIGHT)->print(p->getName());
		Utils::DrawCircle(RENDER, r.x + r.w - 10, r.y + r.h, 4, p->isConnect());
	}

}
