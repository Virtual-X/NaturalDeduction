/*
 * NodeBinaryOperator.h
 *
 *  Created on: Feb 8, 2014
 *      Author: igor
 */

#ifndef NODEBINARYOPERATOR_H_
#define NODEBINARYOPERATOR_H_

#include "Node.h"

#include <memory>

class BinaryOperator;

class NodeBinaryOperator: public Node {
public:
	NodeBinaryOperator(
			const shared_ptr<Node>& leftNode,
			const shared_ptr<BinaryOperator>& binaryOperator,
			const shared_ptr<Node>& rightNode);
	virtual ~NodeBinaryOperator();

	virtual Value Evaluate() const;
	virtual shared_ptr<Node> Simplify() const;
	virtual void Print(ostream& out) const;
	virtual int GetPrecedence() const;

private:
	shared_ptr<Node> leftNode;
	shared_ptr<BinaryOperator> binaryOperator;
	shared_ptr<Node> rightNode;
};

#endif /* NODEBINARYOPERATOR_H_ */
