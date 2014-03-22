/*
 * NodeLiteral.h
 *
 *  Created on: Feb 5, 2014
 *      Author: igor
 */

#ifndef NODELITERAL_H_
#define NODELITERAL_H_

#include "Node.h"

class NodeLiteral : public Node {
public:
	NodeLiteral(string name);
	virtual ~NodeLiteral();

	void SetValue(Value newValue);

	virtual Value Evaluate() const;
	virtual shared_ptr<Node> Simplify() const;
	virtual void Print(ostream& out) const;

private:
	string name;
	Value value;
};

#endif /* NODELITERAL_H_ */
