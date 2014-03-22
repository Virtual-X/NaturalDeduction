/*
 * ArgumentParser.h
 *
 *  Created on: Feb 3, 2014
 *      Author: igor
 */

#ifndef ARGUMENTPARSER_H_
#define ARGUMENTPARSER_H_

#include <string>
#include <vector>
#include <map>
#include <memory>
using namespace std;

class Statement;
class VariablesContainer;

class ArgumentParser {
public:
	ArgumentParser(VariablesContainer& variables);
	virtual ~ArgumentParser();

	void Parse(string argument, vector<Statement>& statements, Statement& conclusion);
private:
	VariablesContainer& variables;
};

#endif /* ARGUMENTPARSER_H_ */
