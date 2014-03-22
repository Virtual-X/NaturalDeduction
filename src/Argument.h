/*
 * Argument.h
 *
 *  Created on: Feb 3, 2014
 *      Author: igor
 */

#ifndef ARGUMENT_H_
#define ARGUMENT_H_

#include "Statement.h"
#include "VariablesContainer.h"

#include <string>
#include <vector>
using namespace std;

class Argument {
public:
	Argument();
	explicit Argument(const string& argument);
	virtual ~Argument();

	bool IsValid();
	bool DeduceConclusion();

	void PrintVariables(ostream& out) const;
	void PrintValidation(ostream& out, bool printFalseStatements) const;

	void PrintStatements(ostream& out) const;
	void PrintConclusion(ostream& out) const;
	void PrintDeductions(ostream& out) const;

private:
	VariablesContainer variables;
	vector<Statement> statements;
	vector<Statement> deductions;
	Statement conclusion;

	void PrintStatements(ostream& out, const vector<Statement>& statements, int offset) const;
};

#endif /* ARGUMENT_H_ */
