/*
 * TableSolver.h
 *
 *  Created on: Feb 8, 2014
 *      Author: igor
 */

#ifndef TABLESOLVER_H_
#define TABLESOLVER_H_

#include <string>
#include <vector>
using namespace std;

class VariablesContainer;
class Statement;
enum class Value;

class TableSolver {
public:
	TableSolver(const VariablesContainer& variables);
	virtual ~TableSolver();

	// limitation: a = undefined -> a^~a = undefined
	bool IsArgumentValid(const vector<Statement>& statements, const Statement& conclusion, bool testUndefinedValues);
	void PrintArgumentValidation(ostream& out, const vector<Statement>& statements, const Statement& conclusion, bool testUndefinedValues, bool printFalseStatements);
private:

	bool IsArgumentTrue(const vector<Statement>& statements, const Statement& conclusion);
	void PrintArgumentState(ostream& out, const vector<Statement>& statements, const Statement& conclusion, bool printFalseStatements);

	const VariablesContainer& variables;
};

#endif /* TABLESOLVER_H_ */
