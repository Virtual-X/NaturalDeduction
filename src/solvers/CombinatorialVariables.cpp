/*
 * CombinatorialVariables.cpp
 *
 *  Created on: Feb 8, 2014
 *      Author: igor
 */

#include "CombinatorialVariables.h"
#include "NodeLiteral.h"
#include "VariablesContainer.h"
#include "Value.h"

CombinatorialVariables::CombinatorialVariables(
		const VariablesContainer& variables,
		bool testUndefinedValues,
		function<bool()> testValues)
: variables(variables),
  variableNames(variables.GetVariableNames()),
  values(GetTestValues(testUndefinedValues)),
  testValues(testValues) {
}

CombinatorialVariables::~CombinatorialVariables() {
}

void CombinatorialVariables::ElementChanged(size_t index, size_t value) {
	variables.SetVariableValue(variableNames[index], values[value]);
}

bool CombinatorialVariables::EvaluateElements(const vector<size_t>& values) {
	return testValues();
}

vector<Value> CombinatorialVariables::GetTestValues(bool testUndefinedValues) {
	vector<Value> values{ Value::True, Value::False };
	if (testUndefinedValues) {
		values.push_back(Value::Undefined);
	}
	return values;
}
