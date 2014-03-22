/*
 * NodeConstant.cpp
 *
 *  Created on: Feb 7, 2014
 *      Author: igor
 */

#include "NodeConstant.h"
#include "Syntax.h"

NodeConstant::NodeConstant(bool isTrue)
: isTrue(isTrue) {
}

NodeConstant::~NodeConstant() {
}

const shared_ptr<Node> NodeConstant::True(new NodeConstant(true));

const shared_ptr<Node> NodeConstant::False(new NodeConstant(false));

Value NodeConstant::Evaluate() const {
	return isTrue ? Value::True : Value::False;
}

shared_ptr<Node> NodeConstant::Simplify() const {
	return shared_ptr<Node>();
}

void NodeConstant::Print(ostream& out) const {
	out << (isTrue ? Syntax::True : Syntax::False);
}
