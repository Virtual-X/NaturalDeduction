/*
 * BinaryOperatorAnd.h
 *
 *  Created on: Feb 7, 2014
 *      Author: igor
 */

#ifndef BINARYOPERATORAND_H_
#define BINARYOPERATORAND_H_

#include "BinaryOperator.h"

class BinaryOperatorAnd: public BinaryOperator {
public:
	BinaryOperatorAnd();
	virtual ~BinaryOperatorAnd();

	virtual Value Apply(Value left, Value right) const;

	virtual void Print(ostream& out) const;

	virtual int GetPrecedence() const;
};

#endif /* BINARYOPERATORAND_H_ */
