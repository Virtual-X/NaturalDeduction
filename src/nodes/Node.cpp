/*
 * Node.cpp
 *
 *  Created on: Feb 5, 2014
 *      Author: igor
 */

#include "Node.h"
#include "Syntax.h"

#include <iostream>

Node::Node() {
}

Node::~Node() {
}

int Node::GetPrecedence() const {
	return Syntax::DefaultPrecedence;
}

void Node::PrintNode(ostream& out, const Node& node, bool needBrackets) {
	if (needBrackets) {
		out << Syntax::BracketOpen;
	}
	node.Print(out);
	if (needBrackets) {
		out << Syntax::BracketClose;
	}
}
