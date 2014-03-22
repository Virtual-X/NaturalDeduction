/*
 * BinaryOperator.h
 *
 *  Created on: Feb 7, 2014
 *      Author: igor
 */

#ifndef BINARYOPERATOR_H_
#define BINARYOPERATOR_H_

#include "Value.h"

#include <string>
using namespace std;

class BinaryOperator {
public:
	BinaryOperator();
	virtual ~BinaryOperator();

	virtual Value Apply(Value left, Value right) const = 0;

	virtual void Print(ostream& out) const = 0;

	virtual int GetPrecedence() const = 0;
};

#endif /* BINARYOPERATOR_H_ */
