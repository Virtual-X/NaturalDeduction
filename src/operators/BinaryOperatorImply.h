/*
 * BinaryOperatorImply.h
 *
 *  Created on: Feb 7, 2014
 *      Author: igor
 */

#ifndef BINARYOPERATORIMPLY_H_
#define BINARYOPERATORIMPLY_H_

#include "BinaryOperator.h"

class BinaryOperatorImply: public BinaryOperator {
public:
	BinaryOperatorImply();
	virtual ~BinaryOperatorImply();

	virtual Value Apply(Value left, Value right) const;

	virtual void Print(ostream& out) const;

	virtual int GetPrecedence() const;
};

#endif /* BINARYOPERATORIMPLY_H_ */
