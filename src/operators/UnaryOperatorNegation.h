/*
 * UnaryOperatorNegation.h
 *
 *  Created on: Feb 8, 2014
 *      Author: igor
 */

#ifndef UNARYOPERATORNEGATION_H_
#define UNARYOPERATORNEGATION_H_

#include "UnaryOperator.h"

class UnaryOperatorNegation: public UnaryOperator {
public:
	UnaryOperatorNegation();
	virtual ~UnaryOperatorNegation();

	virtual Value Apply(Value value) const;

	virtual void Print(ostream& out) const;
};

#endif /* UNARYOPERATORNEGATION_H_ */
