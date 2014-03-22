/*
 * UnaryOperatorNegation.cpp
 *
 *  Created on: Feb 8, 2014
 *      Author: igor
 */

#include "UnaryOperatorNegation.h"
#include "Syntax.h"

UnaryOperatorNegation::UnaryOperatorNegation() {
}

UnaryOperatorNegation::~UnaryOperatorNegation() {
}

Value UnaryOperatorNegation::Apply(Value value) const {
	return SwitchValue(value, Value::Undefined, Value::True, Value::False);
}

void UnaryOperatorNegation::Print(ostream& out) const {
	out << Syntax::Negation;
}
