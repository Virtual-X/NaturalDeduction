/*
 * BinaryOperatorOr.h
 *
 *  Created on: Feb 7, 2014
 *      Author: igor
 */

#ifndef BINARYOPERATOROR_H_
#define BINARYOPERATOROR_H_

#include "BinaryOperator.h"

class BinaryOperatorOr: public BinaryOperator {
public:
	BinaryOperatorOr();
	virtual ~BinaryOperatorOr();

	virtual Value Apply(Value left, Value right) const;

	virtual void Print(ostream& out) const;

	virtual int GetPrecedence() const;
};

#endif /* BINARYOPERATOROR_H_ */
