/*
 * VariablesContainer.h
 *
 *  Created on: Feb 9, 2014
 *      Author: igor
 */

#ifndef VARIABLESCONTAINER_H_
#define VARIABLESCONTAINER_H_

#include <map>
#include <memory>
#include <string>
#include <vector>
using namespace std;

enum class Value;
class NodeLiteral;

class VariablesContainer {
public:
	VariablesContainer();
	virtual ~VariablesContainer();

	void AddVariable(const string& variableName, const  shared_ptr<NodeLiteral>& variable);
	vector<string> GetVariableNames() const;
	shared_ptr<NodeLiteral> GetVariable(const string& variableName) const;

	void SetVariableValue(const string& variableName, Value value) const; // const because variables are not considered part of the container

private:
	map<string, shared_ptr<NodeLiteral>> variables;
};

#endif /* VARIABLESCONTAINER_H_ */
