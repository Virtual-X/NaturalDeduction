/*
 * Node.h
 *
 *  Created on: Feb 5, 2014
 *      Author: igor
 */

#ifndef NODE_H_
#define NODE_H_

#include "Value.h"

#include <string>
#include <memory>
using namespace std;

class Node {
public:
	Node();
	virtual ~Node();

	virtual Value Evaluate() const = 0;
	// return shared_ptr<Node>() if cannot simplify
	virtual shared_ptr<Node> Simplify() const = 0;
	virtual void Print(ostream& out) const = 0;
	virtual int GetPrecedence() const;

protected:
	static void PrintNode(ostream& out, const Node& node, bool needBrackets);
};

#endif /* NODE_H_ */
