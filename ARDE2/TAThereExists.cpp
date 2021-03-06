#include "TAThereExists.h"
#include "TALessThanOrEquals.h"
#include "TAEqual.h"
#include "TAGreaterThan.h"
#include "TAGreaterThanOrEquals.h"
#include "TALessThan.h"
#include "TALessThanOrEquals.h"
std::string TAThereExists::name = "TAThereExists";
TAThereExists::TAThereExists(TADomain domain, std::string operationName, Type &variable)
{
	this->operationName = operationName;
	this->vector = domain.getVector();
	this->variable = &variable;

}
void TAThereExists::evaluate()
{
	if (this->operationName == "TAEqual")
	{
		int x = 0;
		for (std::vector<Type*>::iterator it = vector.begin(); it != vector.end(); ++it)
		{
			this->operation = new TAEqual(vector.at(x++), variable);
			this->operation->evaluate();
			if (this->operation->getResult().getValue() == true)
			{
				result.setValue(true);
				break;
			}
			else
				result.setValue(false);
		}
	}
	else
		if (this->operationName == "TAGreaterThan")
		{
			int x = 0;
			for (std::vector<Type*>::iterator it = vector.begin(); it != vector.end(); ++it)
			{
				this->operation = new TAGreaterThan(vector.at(x++), variable);
				this->operation->evaluate();
				if (this->operation->getResult().getValue() == true)
				{
					result.setValue(true);
					break;
				}
				else
					result.setValue(false);
			}
		}
		else
			if (this->operationName == "TAGreaterThanOrEquals")
			{
				int x = 0;
				for (std::vector<Type*>::iterator it = vector.begin(); it != vector.end(); ++it)
				{
					this->operation = new TAGreaterThanOrEquals(vector.at(x++), variable);
					this->operation->evaluate();
					if (this->operation->getResult().getValue() == true)
					{
						result.setValue(true);
						break;
					}
					else
						result.setValue(false);
				}
			}
			else
				if (this->operationName == "TALessThan")
				{
					int x = 0;
					for (std::vector<Type*>::iterator it = vector.begin(); it != vector.end(); ++it)
					{
						this->operation = new TALessThan(vector.at(x++), variable);
						this->operation->evaluate();
						if (this->operation->getResult().getValue() == true)
						{
							result.setValue(true);
							break;
						}
						else
							result.setValue(false);
					}
				}
				else
					if (this->operationName == "TALessThanOrEquals")
					{
						int x = 0;
						for (std::vector<Type*>::iterator it = vector.begin(); it != vector.end(); ++it)
						{
							this->operation = new TALessThanOrEquals(vector.at(x++), variable);
							this->operation->evaluate();
							if (this->operation->getResult().getValue() == true)
							{
								result.setValue(true);
								break;
							}
							else
								result.setValue(false);
						}
					}
}
void TAThereExists::List()
{
}
std::string TAThereExists::getOperationName()
{
	return std::string();
}

TABool TAThereExists::getResult()
{
	return result;
}
