/*
 * BinaryOperatorAnd.cpp
 *
 *  Created on: Feb 7, 2014
 *      Author: igor
 */

#include "BinaryOperatorAnd.h"
#include "Syntax.h"

BinaryOperatorAnd::BinaryOperatorAnd() {
}

BinaryOperatorAnd::~BinaryOperatorAnd() {
}

Value BinaryOperatorAnd::Apply(Value left, Value right) const {
	return (left == Value::False || right == Value::False) ? Value::False :
			((left == Value::Undefined || right == Value::Undefined) ? Value::Undefined : Value::True);
}

void BinaryOperatorAnd::Print(ostream& out) const {
	out << Syntax::And;
}

int BinaryOperatorAnd::GetPrecedence() const {
	return Syntax::BinaryOperatorsPrecedence.at(Syntax::And);
}
