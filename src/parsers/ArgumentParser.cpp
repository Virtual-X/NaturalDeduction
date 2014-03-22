/*
 * ArgumentParser.cpp
 *
 *  Created on: Feb 3, 2014
 *      Author: igor
 */

#include "ArgumentParser.h"
#include "StatementParser.h"
#include "Statement.h"
#include "Syntax.h"
#include "MalformedArgumentStringException.h"
#include "StringFunctions.h"

ArgumentParser::ArgumentParser(VariablesContainer& variables)
: variables(variables) {
}

ArgumentParser::~ArgumentParser() {
}

void ArgumentParser::Parse(string argument, vector<Statement>& statements, Statement& conclusion) {
	EraseAllOccurrencies(argument, " ");
	auto ssc = Split(argument, Syntax::ConclusionPrefix);
	if (ssc.size() < 2) {
		throw MalformedArgumentStringException("Missing conclusion!");
	}
	else if (ssc.size() > 2) {
		throw MalformedArgumentStringException("More than one conclusion!");
	}
	auto ss = Split(ssc[0], Syntax::StatementSeparator);
	StatementParser p(variables);
	for (auto s : ss) {
		statements.push_back(p.Parse(s));
	}
	conclusion = p.Parse(ssc[1]);
}

