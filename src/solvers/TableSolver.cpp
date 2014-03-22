/*
 * TableSolver.cpp
 *
 *  Created on: Feb 8, 2014
 *      Author: igor
 */

#include "TableSolver.h"
#include "Statement.h"
#include "Value.h"
#include "CombinatorialVariables.h"
#include "Syntax.h"
#include "NodeLiteral.h"
#include "VariablesContainer.h"

#include <iostream>

TableSolver::TableSolver(const VariablesContainer& variables)
: variables(variables) {
}

TableSolver::~TableSolver() {
}

bool TableSolver::IsArgumentValid(const vector<Statement>& statements, const Statement& conclusion, bool testUndefinedValues) {
	bool isValid = true;
	CombinatorialVariables cv(
			variables,
			testUndefinedValues,
			[&] { isValid = IsArgumentTrue(statements, conclusion); return isValid; });
	Combinatorial c(variables.GetVariableNames().size(), testUndefinedValues ? 3 : 2);
	c.Enumerate(cv);
	return isValid;
}

void TableSolver::PrintArgumentValidation(ostream& out, const vector<Statement>& statements, const Statement& conclusion, bool testUndefinedValues, bool printFalseStatements) {
	CombinatorialVariables cv(
			variables,
			testUndefinedValues,
			[&] { PrintArgumentState(out, statements, conclusion, printFalseStatements); return true; });
	Combinatorial c(variables.GetVariableNames().size(), testUndefinedValues ? 3 : 2);
	c.Enumerate(cv);
}

bool TableSolver::IsArgumentTrue(const vector<Statement>& statements, const Statement& conclusion) {
	for (const auto& s : statements) {
		auto v = s.Evaluate();
		if (v == Value::False) {
			return true;
		} else if (v == Value::Undefined) {
			return false;
		}
	}
	return conclusion.Evaluate() == Value::True;
}

void TableSolver::PrintArgumentState(ostream& out, const vector<Statement>& statements, const Statement& conclusion, bool printFalseStatements) {
	if (!printFalseStatements) {
		for (const auto& s : statements) {
			if (s.Evaluate() == Value::False)
				return;
		}
	}

	for (const auto& var : variables.GetVariableNames()) {
		out << var << "=";
		variables.GetVariable(var)->Print(out);
		out << string(" ");
	}
	out << string("::");
	for (const auto& s : statements) {
		out << string(" ");
		out << SwitchValue(s.Evaluate(), Syntax::Undefined, Syntax::False, Syntax::True);
		out << string(" /");
	}
	out << string("/ ");
	out << SwitchValue(conclusion.Evaluate(), Syntax::Undefined, Syntax::False, Syntax::True);
	out << endl;
}
