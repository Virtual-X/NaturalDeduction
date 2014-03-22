/*
 * VariablesContainer.cpp
 *
 *  Created on: Feb 9, 2014
 *      Author: igor
 */

#include "VariablesContainer.h"
#include "NodeLiteral.h"
#include "Value.h"

VariablesContainer::VariablesContainer() {
}

VariablesContainer::~VariablesContainer() {
}

void VariablesContainer::AddVariable(const string& variableName, const shared_ptr<NodeLiteral>& variable) {
	variables[variableName] = variable;
}

vector<string> VariablesContainer::GetVariableNames() const {
	vector<string> names;
	for (const auto& var : variables) {
		names.push_back(var.first);
	}
	return names;
}

shared_ptr<NodeLiteral> VariablesContainer::GetVariable(const string& variableName) const {
	auto var = variables.find(variableName);
	return var != variables.end() ? var->second : shared_ptr<NodeLiteral>();
}

void VariablesContainer::SetVariableValue(const string& variableName, Value value) const {
	variables.at(variableName)->SetValue(value);
}
