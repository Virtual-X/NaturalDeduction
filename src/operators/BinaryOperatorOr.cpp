/*
 * BinaryOperatorOr.cpp
 *
 *  Created on: Feb 7, 2014
 *      Author: igor
 */

#include "BinaryOperatorOr.h"
#include "Syntax.h"

BinaryOperatorOr::BinaryOperatorOr() {

}

BinaryOperatorOr::~BinaryOperatorOr() {
}

Value BinaryOperatorOr::Apply(Value left, Value right) const {
	return (left == Value::True || right == Value::True) ? Value::True :
			((left == Value::Undefined || right == Value::Undefined) ? Value::Undefined : Value::False);
}

void BinaryOperatorOr::Print(ostream& out) const {
	out << Syntax::Or;
}

int BinaryOperatorOr::GetPrecedence() const {
	return Syntax::BinaryOperatorsPrecedence.at(Syntax::Or);
}
