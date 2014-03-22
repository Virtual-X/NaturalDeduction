/*
 * Syntax.cpp
 *
 *  Created on: Feb 4, 2014
 *      Author: igor
 */

#include "Syntax.h"

const string Syntax::ConclusionPrefix = "//";
const string Syntax::StatementSeparator = "/";

const string Syntax::BracketOpen = "(";
const string Syntax::BracketClose = ")";

const string Syntax::True = "T";
const string Syntax::False = "F";
const string Syntax::Undefined = "?";

const vector<string> Syntax::Constants{ True, False };

const string Syntax::Negation = "~";

const vector<string> Syntax::UnaryOperators{ Negation };

const string Syntax::And = "^";
const string Syntax::Or = "V";
const string Syntax::Imply = "->";

const vector<string> Syntax::BinaryOperators{ And, Or, Imply};

const map<string, int> Syntax::BinaryOperatorsPrecedence{
	{ And, 3 },
	{ Or, 3 },
	{ Imply, 1 }
};

const int Syntax::DefaultPrecedence = 10;
