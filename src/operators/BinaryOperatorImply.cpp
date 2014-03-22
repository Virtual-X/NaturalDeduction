/*
 * BinaryOperatorImply.cpp
 *
 *  Created on: Feb 7, 2014
 *      Author: igor
 */

#include "BinaryOperatorImply.h"
#include "Syntax.h"

BinaryOperatorImply::BinaryOperatorImply() {

}

BinaryOperatorImply::~BinaryOperatorImply() {
}

Value BinaryOperatorImply::Apply(Value left, Value right) const {
	return (left == Value::False || right == Value::True) ? Value::True :
			((left == Value::Undefined || right == Value::Undefined) ? Value::Undefined : Value::False);
}

void BinaryOperatorImply::Print(ostream& out) const {
	out << Syntax::Imply;
}

int BinaryOperatorImply::GetPrecedence() const {
	return Syntax::BinaryOperatorsPrecedence.at(Syntax::Imply);
}
