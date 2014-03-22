/*
 * Statement.h
 *
 *  Created on: Feb 3, 2014
 *      Author: igor
 */

#ifndef STATEMENT_H_
#define STATEMENT_H_

#include "Value.h"

#include <string>
#include <memory>
using namespace std;

class Node;

class Statement {
public:
	Statement();
	explicit Statement(const shared_ptr<Node>& node);
	virtual ~Statement();

	Value Evaluate() const;
	void Print(ostream& out) const;

private:
	shared_ptr<Node> node;
};

ostream& operator << (ostream& out, const Statement& statement);

#endif /* STATEMENT_H_ */
