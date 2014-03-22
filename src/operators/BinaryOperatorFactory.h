/*
 * BinaryOperatorFactory.h
 *
 *  Created on: Feb 7, 2014
 *      Author: igor
 */

#ifndef BINARYOPERATORFACTORY_H_
#define BINARYOPERATORFACTORY_H_

#include <memory>
#include <string>
#include <vector>
#include <map>
#include <functional>
using namespace std;

class BinaryOperator;

class BinaryOperatorFactory {
public:
	BinaryOperatorFactory();
	virtual ~BinaryOperatorFactory();

	const vector<string>& GetOperators() const;

	shared_ptr<BinaryOperator> Create(const string& operatorName);

private:
	const map<string, function<shared_ptr<BinaryOperator>()>> createOperatorFromName;
};

#endif /* BINARYOPERATORFACTORY_H_ */
