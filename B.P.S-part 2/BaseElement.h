#pragma once
#include "Utils.hpp"
#include "Port.h"
#include "TextPrint.h"
enum class SIGNALS
{
	INPUT = 1,
	OUTPUT = 2,
	IO = 3
};

class BaseElement
{
public:
	BaseElement(Point pos, std::string title, SIGNALS signals, std::vector<Port*> inpPorts, std::vector<Port*> outPorts);

	std::vector<Port*>* getInputPorts();
	std::vector<Port*>* getOutputPorts();

	void addInputPort(Port* p);
	void addOutputPort(Port* p);

	std::string getTitle();

	SIGNALS getSignal();

	void Draw();

private:
	std::vector<Port*> inpPorts, outPorts;
	std::string title;
	SIGNALS sig;
	Point pos; // ? NOT GRAPHICKS 
};