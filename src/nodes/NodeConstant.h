/*
 * NodeConstant.h
 *
 *  Created on: Feb 7, 2014
 *      Author: igor
 */

#ifndef NODECONSTANT_H_
#define NODECONSTANT_H_

#include "Node.h"

class NodeConstant : public Node {
	NodeConstant(bool isTrue);

public:
	virtual ~NodeConstant();

	static const shared_ptr<Node> True;
	static const shared_ptr<Node> False;

	virtual Value Evaluate() const;
	virtual shared_ptr<Node> Simplify() const;
	virtual void Print(ostream& out) const;

private:
	bool isTrue;
};

#endif /* NODECONSTANT_H_ */
