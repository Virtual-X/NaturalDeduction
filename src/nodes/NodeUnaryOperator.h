/*
 * NodeUnaryOperator.h
 *
 *  Created on: Feb 8, 2014
 *      Author: igor
 */

#ifndef NODEUNARYOPERATOR_H_
#define NODEUNARYOPERATOR_H_

#include "Node.h"

#include <memory>

class UnaryOperator;

class NodeUnaryOperator: public Node {
public:
	NodeUnaryOperator(
			const shared_ptr<UnaryOperator>& unaryOperator,
			const shared_ptr<Node>& rightNode);
	virtual ~NodeUnaryOperator();

	virtual Value Evaluate() const;
	virtual shared_ptr<Node> Simplify() const;
	virtual void Print(ostream& out) const;

private:
	shared_ptr<UnaryOperator> unaryOperator;
	shared_ptr<Node> node;
};

#endif /* NODEUNARYOPERATOR_H_ */
