/*
 * Argument.cpp
 *
 *  Created on: Feb 3, 2014
 *      Author: igor
 */

#include "Argument.h"
#include "ArgumentParser.h"
#include "TableSolver.h"

#include <iostream>

Argument::Argument() {
}

Argument::Argument(const string& argument) {
	ArgumentParser parser(variables);
	parser.Parse(argument, statements, conclusion);
}

Argument::~Argument() {
}

bool Argument::IsValid() {
	TableSolver s(variables);
	return s.IsArgumentValid(statements, conclusion, false);
}

bool Argument::DeduceConclusion() {
	// todo
	return false;
}

void Argument::PrintVariables(ostream& out) const {
	out << "Variables:";
	for (const auto& var : variables.GetVariableNames()) {
		out << " " << var;
	}
	out << endl;
}

void Argument::PrintValidation(ostream& out, bool printFalseStatements) const {
	TableSolver s(variables);
	s.PrintArgumentValidation(out, statements, conclusion, false, printFalseStatements);
}

void Argument::PrintStatements(ostream& out) const {
	PrintStatements(out, statements, 0);
}

void Argument::PrintConclusion(ostream& out) const {
	PrintStatements(out, vector<Statement>{ conclusion }, -1);
}

void Argument::PrintDeductions(ostream& out) const {
	PrintStatements(out, deductions, statements.size());
}

void Argument::PrintStatements(ostream& out, const vector<Statement>& statements, int offset) const {
	for (const auto& s : statements) {
		out << ++offset << "." << s << endl;
	}
}
