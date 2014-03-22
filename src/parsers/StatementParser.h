/*
 * StatementParser.h
 *
 *  Created on: Feb 8, 2014
 *      Author: igor
 */

#ifndef STATEMENTPARSER_H_
#define STATEMENTPARSER_H_

#include <string>
#include <vector>
#include <memory>
using namespace std;

class Statement;
class Node;
class BinaryOperatorFactory;
class UnaryOperatorFactory;
class VariablesContainer;

class StatementParser {
public:
	StatementParser(VariablesContainer& variables);
	virtual ~StatementParser();

	Statement Parse(const string& statement);
private:

	// http://en.wikipedia.org/wiki/Operator-precedence_parser
	shared_ptr<Node> ParseExpression();
	shared_ptr<Node> ParsePrimary();
	shared_ptr<Node> ParsePartialExpression(
			const shared_ptr<Node>& current,
			int minPrecedence);

	VariablesContainer& variables;

	string statement;
	size_t pos;

	const shared_ptr<BinaryOperatorFactory> binaryOperatorFactory;
	const shared_ptr<UnaryOperatorFactory> unaryOperatorFactory;

	const vector<string> literalFollowers;
};

#endif /* STATEMENTPARSER_H_ */
