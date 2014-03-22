/*
 * NodeUnaryOperator.cpp
 *
 *  Created on: Feb 8, 2014
 *      Author: igor
 */

#include "NodeUnaryOperator.h"
#include "UnaryOperator.h"
#include "Syntax.h"

NodeUnaryOperator::NodeUnaryOperator(
	const shared_ptr<UnaryOperator>& unaryOperator,
	const shared_ptr<Node>& node)
: unaryOperator(unaryOperator),
  node(node) {
}

NodeUnaryOperator::~NodeUnaryOperator() {
}

Value NodeUnaryOperator::Evaluate() const {
	return unaryOperator->Apply(node->Evaluate());
}

shared_ptr<Node> NodeUnaryOperator::Simplify() const {
	auto n = node->Simplify();
	if (!n) n = node;
	throw 0; //unaryOperator->Apply(node);
}

void NodeUnaryOperator::Print(ostream& out) const {
	unaryOperator->Print(out);
	PrintNode(out, *node, node->GetPrecedence() < GetPrecedence());
}
