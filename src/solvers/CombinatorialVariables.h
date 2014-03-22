/*
 * CombinatorialVariables.h
 *
 *  Created on: Feb 8, 2014
 *      Author: igor
 */

#ifndef COMBINATORIALVARIABLES_H_
#define COMBINATORIALVARIABLES_H_

#include "Combinatorial.h"

#include <string>
#include <vector>
#include <functional>
using namespace std;

enum class Value;
class Statement;
class VariablesContainer;

class CombinatorialVariables : public Combinatorial::Handler {
public:
	CombinatorialVariables(
			const VariablesContainer& variables,
			bool testUndefinedValues,
			function<bool()> testValues);
	virtual ~CombinatorialVariables();

	virtual void ElementChanged(size_t index, size_t value);
	virtual bool EvaluateElements(const vector<size_t>& values);

private:
	static vector<Value> GetTestValues(bool testUndefinedValues);

	const VariablesContainer& variables;
	vector<string> variableNames;
	vector<Value> values;
	function<bool()> testValues;
};

#endif /* COMBINATORIALVARIABLES_H_ */
