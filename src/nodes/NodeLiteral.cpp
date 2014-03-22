/*
 * NodeLiteral.cpp
 *
 *  Created on: Feb 5, 2014
 *      Author: igor
 */

#include "NodeLiteral.h"
#include "NodeConstant.h"

NodeLiteral::NodeLiteral(string name)
: name(name),
  value(Value::Undefined) {
}

NodeLiteral::~NodeLiteral() {
}

void NodeLiteral::SetValue(Value newValue) {
	value = newValue;
}

Value NodeLiteral::Evaluate() const {
	return value;
}

shared_ptr<Node> NodeLiteral::Simplify() const {
	return SwitchValue(value, shared_ptr<Node>(), NodeConstant::False, NodeConstant::True);
}

void NodeLiteral::Print(ostream& out) const {
	if (IsUndefined(value)) {
		out << name;
	} else {
		Simplify()->Print(out);
	}
}

