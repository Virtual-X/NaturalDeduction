/*
 * InferenceRule.cpp
 *
 *  Created on: Feb 12, 2014
 *      Author: igor
 */

#include "InferenceRule.h"
#include "ArgumentParser.h"

InferenceRule::InferenceRule(const string& name, const string& description, const string& argument, VariablesContainer& variables)
: name(name),
  description(description) {
	ArgumentParser parser(variables);
	parser.Parse(argument, conditions, deduction);
}

InferenceRule::~InferenceRule() {
}

