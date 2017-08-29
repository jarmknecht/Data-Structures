/* 
Jonathan Armknecht
Project 11
jonathan.armknecht@gmail.com
*/

#include "MyExpressionManager.h"
#include <ctype.h>
#include <stack>

MyManager::MyManager()
{
}

MyManager::~MyManager()
{
}

int MyManager::CheckPrecedence(const Token& t) {
	if (t.Type == TOKENTYPE_OP_PLUS || t.Type == TOKENTYPE_OP_MINUS) {
		return 1;
	}
	else if (t.Type == TOKENTYPE_OP_TIMES || t.Type == TOKENTYPE_OP_DIVIDE) {
		return 2;
	}
	else {
		return 0;
	}
}

Token MyManager::ScanInt(const std::string & str, size_t & pos)
{
	if (pos >= str.length()) {
		throw std::exception("Starting position is greater than size of expression. Can't Scan!");
	}
	if (!isdigit(str[pos])) {
		throw std::exception("Starting position does not point to an integer. Can't Scan!");
	}
	
	int number = 0;

	while (str[pos] >= '0' && str[pos] <= '9') {
		number = number * 10 + str[pos] - '0';
		pos++;
	}
	
	Token t(TOKENTYPE_NUMBER, number);
	return t;
}

void MyManager::TokenizeString(const std::string & str, std::queue<Token>& tokenQueue)
{
	for (size_t i = 0; i < str.length(); i++) {
		Token t(TOKENTYPE_UNKNOWN);

		if (isdigit(str[i])) {
			t = ScanInt(str, i);
			tokenQueue.push(t);
			i--;
		}
		else if (str[i] == '+') {
			t = TOKENTYPE_OP_PLUS;
			tokenQueue.push(t);
		}
		else if (str[i] == '-') {
			t = TOKENTYPE_OP_MINUS;
			tokenQueue.push(t);
		}
		else if (str[i] == '*') {
			t = TOKENTYPE_OP_TIMES;
			tokenQueue.push(t);
		}
		else if (str[i] == '/') {
			t = TOKENTYPE_OP_DIVIDE;
			tokenQueue.push(t);
		}
		else if (str[i] == '(') {
			t = TOKENTYPE_PAR_OPEN;
			tokenQueue.push(t);
		}
		else if (str[i] == ')') {
			t = TOKENTYPE_PAR_CLOSE;
			tokenQueue.push(t);
		}
		else if (isspace(str[i])) {
		//It's a space do nothing with it
		}
		else {
			throw std::exception("Unknown character. Can't Tokenize!");
		}
	}
}

bool MyManager::IsBalanced(std::queue<Token>& inputQueue)
{
	std::stack<Token> matchPar;
	
	while (!inputQueue.empty()) {
		Token t = inputQueue.front();

		if (t.Type == TOKENTYPE_PAR_OPEN) {
			matchPar.push(t);
		}
		else if (t.Type == TOKENTYPE_PAR_CLOSE) {
			if (matchPar.empty()) {
				return false;
			}
			else {
				matchPar.pop();
			}
		}
		inputQueue.pop();
	}
	if (matchPar.empty()) {
		return true;
	}
	else {
		return false;
	}
}

void MyManager::InfixToPostfix(std::queue<Token>& inputQueue, std::queue<Token>& outputQueue)
{
	std::stack<Token> operatorStack;
	Token op;
	Token t;

	while (!inputQueue.empty()) {
		t = inputQueue.front();
		
		inputQueue.pop();

		if (t.Type == TOKENTYPE_NUMBER) {
			outputQueue.push(t);
		}
		else if (t.Type == TOKENTYPE_OP_DIVIDE || t.Type == TOKENTYPE_OP_MINUS ||
			t.Type == TOKENTYPE_OP_PLUS || t.Type == TOKENTYPE_OP_TIMES) {
			while (!operatorStack.empty()) {
				op = operatorStack.top();
				if (op.Type == TOKENTYPE_PAR_OPEN) {
					break;
				}
				else if (CheckPrecedence(t) > CheckPrecedence(op)) {
					break;
				}
				operatorStack.pop();
				outputQueue.push(op);
			}
			operatorStack.push(t);
		}
		else if (t.Type == TOKENTYPE_PAR_OPEN) {
			operatorStack.push(t);
		}
		else if (t.Type == TOKENTYPE_PAR_CLOSE) {
			while (true) {
				if (operatorStack.empty()) {
					throw std::exception("Mismatched parentheses. Cannot convert to postfix!");
				}
				op = operatorStack.top();
				operatorStack.pop();
				if (op.Type == TOKENTYPE_PAR_OPEN) {
					break;
				}
				outputQueue.push(op);
			}
		}
	}

	while (!operatorStack.empty()) {
		op = operatorStack.top();
		operatorStack.pop();
		if (op.Type == TOKENTYPE_PAR_OPEN) {
			throw std::exception("Mismatched parentheses. Cannot convert to postfix!");
		}
		outputQueue.push(op);
	}
}

int MyManager::PostfixEvaluate(std::queue<Token>& inputQueue)
{
	int result = 0;
	int right = 0;
	int left = 0;

	std::stack<int> evaluationStack;
	Token t;

	while (!inputQueue.empty()) {
		t = inputQueue.front();
		inputQueue.pop();

		if (t.Type == TOKENTYPE_NUMBER) {
			evaluationStack.push(t.Value);
		}
		else if (t.Type == TOKENTYPE_OP_DIVIDE || t.Type == TOKENTYPE_OP_MINUS ||
			t.Type == TOKENTYPE_OP_PLUS || t.Type == TOKENTYPE_OP_TIMES) {
			if (evaluationStack.size() < 2) {
				throw std::exception("Too many operators. Cannot evaluate expression!");
			}

			right = evaluationStack.top();
			evaluationStack.pop();
			left = evaluationStack.top();
			evaluationStack.pop();

			if (t.Type == TOKENTYPE_OP_DIVIDE) {
				result = left / right;
			}
			else if (t.Type == TOKENTYPE_OP_MINUS) {
				result = left - right;
			}
			else if (t.Type == TOKENTYPE_OP_PLUS) {
				result = left + right;
			}
			else if (t.Type == TOKENTYPE_OP_TIMES) {
				result = left * right;
			}
			evaluationStack.push(result);
		}
		else {
			throw std::exception("Invalid token. Cannot evaluate expression!");
		}
	}

	if (evaluationStack.size() > 1) {
		throw std::exception("Missing an operator. Cannot evaluate expression!");
	}
	else {
		result = evaluationStack.top();
		evaluationStack.pop();
	}

	return result;
}
