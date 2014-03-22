/*
 * UnaryOperatorFactory.h
 *
 *  Created on: Feb 8, 2014
 *      Author: igor
 */

#ifndef UNARYOPERATORFACTORY_H_
#define UNARYOPERATORFACTORY_H_

#include <memory>
#include <string>
#include <vector>
#include <map>
#include <functional>
using namespace std;

class UnaryOperator;

class UnaryOperatorFactory {
public:
	UnaryOperatorFactory();
	virtual ~UnaryOperatorFactory();

	const vector<string>& GetOperators() const;

	shared_ptr<UnaryOperator> Create(const string& operatorName);

private:
	const map<string, function<shared_ptr<UnaryOperator>()>> createOperatorFromName;
};

#endif /* UNARYOPERATORFACTORY_H_ */
