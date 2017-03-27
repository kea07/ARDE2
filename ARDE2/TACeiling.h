#pragma once
#include "TAInt.h"
#include "TADouble.h"
#ifndef TACeiling_h
#define TACeiling_h

class TACeiling  {
	static std::string name;
private:
	TAInt result;
	TADouble value1;
public:
	TACeiling(TADouble);
	void setCeiling(TADouble);
	TAInt getValue();
	void evaluate();
	void List();
};
#endif