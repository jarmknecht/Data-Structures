#include <exception>

#include "ExpressionManager.h"

// TODO: Put the name of your header file here:
#include "MyExpressionManager.h"

IExpressionManager *ExpressionManagerFactory::GetExpressionManager()
{
    // TODO: Return a new instance of your expression manager class.
	return new MyManager();
}
