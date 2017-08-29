#pragma once


#include "ExpressionManager.h"

class MyManager :
	public IExpressionManager
{
public:
	MyManager();
	~MyManager();

	int CheckPrecedence(const Token& t);
	virtual Token ScanInt(const std::string &str, size_t &pos);
	virtual void TokenizeString(const std::string &str, std::queue<Token> &tokenQueue);
	virtual bool IsBalanced(std::queue<Token> &inputQueue);
	virtual void InfixToPostfix(std::queue<Token> &inputQueue, std::queue<Token> &outputQueue);
	virtual int PostfixEvaluate(std::queue<Token> &inputQueue);
};