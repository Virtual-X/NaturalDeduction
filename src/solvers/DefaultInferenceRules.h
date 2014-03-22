/*
 * DefaultInferenceRules.h
 *
 *  Created on: Feb 12, 2014
 *      Author: igor
 */

#ifndef DEFAULTINFERENCERULES_H_
#define DEFAULTINFERENCERULES_H_

#include <string>
#include <vector>
using namespace std;

class InferenceRule;
class VariablesContainer;

class DefaultInferenceRules {
public:
	DefaultInferenceRules(VariablesContainer& variables);
	virtual ~DefaultInferenceRules();

	const vector<InferenceRule>& GetInferenceRules() const;

private:
	void Add(const string& name, const string& description, const string& argument);
	void AddAllRules();

	vector<InferenceRule> rules;
	VariablesContainer& variables;
};

#endif /* DEFAULTINFERENCERULES_H_ */
