/*
 * Syntax.h
 *
 *  Created on: Feb 4, 2014
 *      Author: igor
 */

#ifndef SYNTAX_H_
#define SYNTAX_H_

#include <string>
#include <vector>
#include <map>
using namespace std;

class Syntax {
public:

	static const string ConclusionPrefix;
	static const string StatementSeparator;

	// todo support () [] {}, needs vector<BracketOpen> and map<BracketOpen, BracketClose>
	static const string BracketOpen;
	static const string BracketClose;

	static const string True;
	static const string False;
	static const string Undefined;

	static const vector<string> Constants;

	static const string Negation;

	static const vector<string> UnaryOperators;

	static const string And;
	static const string Or;
	static const string Imply;

	static const vector<string> BinaryOperators;

	static const map<string, int> BinaryOperatorsPrecedence;

	static const int DefaultPrecedence;
};

#endif /* SYNTAX_H_ */
