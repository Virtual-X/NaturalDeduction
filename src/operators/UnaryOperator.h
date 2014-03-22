/*
 * UnaryOperator.h
 *
 *  Created on: Feb 8, 2014
 *      Author: igor
 */

#ifndef UNARYOPERATOR_H_
#define UNARYOPERATOR_H_

#include "Value.h"

#include <string>
using namespace std;

class UnaryOperator {
public:
	UnaryOperator();
	virtual ~UnaryOperator();

	virtual Value Apply(Value value) const = 0;

	virtual void Print(ostream& out) const = 0;
};

#endif /* UNARYOPERATOR_H_ */
