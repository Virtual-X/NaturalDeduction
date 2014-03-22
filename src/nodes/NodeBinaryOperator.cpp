/*
 * NodeBinaryOperator.cpp
 *
 *  Created on: Feb 8, 2014
 *      Author: igor
 */

#include "NodeBinaryOperator.h"
#include "BinaryOperator.h"
#include "Syntax.h"

NodeBinaryOperator::NodeBinaryOperator(
	const shared_ptr<Node>& leftNode,
	const shared_ptr<BinaryOperator>& binaryOperator,
	const shared_ptr<Node>& rightNode)
: leftNode(leftNode),
  binaryOperator(binaryOperator),
  rightNode(rightNode) {
}

NodeBinaryOperator::~NodeBinaryOperator() {
}

Value NodeBinaryOperator::Evaluate() const {
	return binaryOperator->Apply(leftNode->Evaluate(), rightNode->Evaluate());
}

shared_ptr<Node> NodeBinaryOperator::Simplify() const {
	throw 0;
}

void NodeBinaryOperator::Print(ostream& out) const {
	// redundant for clarity, could be leftNode->GetPrecedence() < GetPrecedence()
	PrintNode(out, *leftNode, leftNode->GetPrecedence() < Syntax::DefaultPrecedence);
	binaryOperator->Print(out);
	// redundant for clarity, could be rightNode->GetPrecedence() <= GetPrecedence()
	PrintNode(out, *rightNode, rightNode->GetPrecedence() < Syntax::DefaultPrecedence);
}

int NodeBinaryOperator::GetPrecedence() const {
	return binaryOperator->GetPrecedence();
}
