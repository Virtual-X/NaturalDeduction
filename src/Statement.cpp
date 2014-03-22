/*
 * Statement.cpp
 *
 *  Created on: Feb 3, 2014
 *      Author: igor
 */

#include "Statement.h"
#include "Node.h"

Statement::Statement() {
}

Statement::Statement(const shared_ptr<Node>& node)
: node(node){

}

Statement::~Statement() {
}

Value Statement::Evaluate() const {
	return node->Evaluate();
}

void Statement::Print(ostream& out) const {
	node->Print(out);
}

ostream& operator << (ostream& out, const Statement& statement) {
	statement.Print(out);
	return out;
}
