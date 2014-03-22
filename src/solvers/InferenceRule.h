/*
 * InferenceRule.h
 *
 *  Created on: Feb 12, 2014
 *      Author: igor
 */

#ifndef INFERENCERULE_H_
#define INFERENCERULE_H_

#include "Argument.h"

class VariablesContainer;

class InferenceRule {
public:
	InferenceRule(const string& name, const string& description, const string& argument, VariablesContainer& variables);
	virtual ~InferenceRule();

private:
	string name;
	string description;

	vector<Statement> conditions;
	Statement deduction;
};

#endif /* INFERENCERULE_H_ */
