/*
 * StatementParser.cpp
 *
 *  Created on: Feb 8, 2014
 *      Author: igor
 */

#include "StatementParser.h"
#include "Statement.h"
#include "Syntax.h"
#include "MalformedArgumentStringException.h"
#include "StringFunctions.h"
#include "NodeLiteral.h"
#include "NodeBinaryOperator.h"
#include "NodeUnaryOperator.h"
#include "NodeConstant.h"
#include "BinaryOperatorFactory.h"
#include "UnaryOperatorFactory.h"
#include "VariablesContainer.h"

StatementParser::StatementParser(VariablesContainer& variables)
: variables(variables),
  statement(),
  pos(0),
  binaryOperatorFactory(new BinaryOperatorFactory()),
  unaryOperatorFactory(new UnaryOperatorFactory()),
  literalFollowers(([&] {
		vector<string> f(binaryOperatorFactory->GetOperators());
		f.push_back(Syntax::BracketClose);
		return f; })()) {
}

StatementParser::~StatementParser() {
}

Statement StatementParser::Parse(const string& statement) {
	this->statement = statement;
	pos = 0;
	auto n = ParseExpression();
	if (pos != statement.size()) {
		throw MalformedArgumentStringException("Some exceeding character found!");
	}
	return Statement(n);
}

shared_ptr<Node> StatementParser::ParseExpression() {
	auto n = ParsePrimary();
	return ParsePartialExpression(n, 0);
}

shared_ptr<Node> StatementParser::ParsePrimary() {
	if (StartsWith(statement, pos, Syntax::BracketOpen)) {
		pos += Syntax::BracketOpen.size();
		auto r = ParseExpression();
		if (!StartsWith(statement, pos, Syntax::BracketClose)) {
			throw MalformedArgumentStringException("Mismatching brackets found!");
		}
		pos += Syntax::BracketClose.size();
		return r;
	}
	size_t operatorIndex;
	const auto& ops = unaryOperatorFactory->GetOperators();
	if (StartsWithAny(statement, pos, ops, operatorIndex)) {
		const string& op(ops[operatorIndex]);
		pos += op.size();
		return make_shared<NodeUnaryOperator>(
				unaryOperatorFactory->Create(op),
				ParsePrimary());
	}
	for (const auto& c : Syntax::Constants) {
		if (StartsWith(statement, pos, c)) {
			pos += c.size();
			return c == Syntax::True ? NodeConstant::True : NodeConstant::False;
		}
	}
	auto follower = FindFirst(statement, pos, literalFollowers, operatorIndex);
	const string& literal = follower != string::npos ?
			statement.substr(pos, follower - pos) :
			statement.substr(pos);
	pos += literal.size();
	auto var = variables.GetVariable(literal);
	if (var) {
		return var;
	}
	shared_ptr<NodeLiteral> lit(new NodeLiteral(literal));
	variables.AddVariable(literal, lit);
	return lit;
}

shared_ptr<Node> StatementParser::ParsePartialExpression(const shared_ptr<Node>& current, int minPrecedence) {
	auto left(current);
	size_t operatorIndex;
	const auto& ops = binaryOperatorFactory->GetOperators();
	while (StartsWithAny(statement, pos, ops, operatorIndex) &&
			Syntax::BinaryOperatorsPrecedence.at(ops[operatorIndex]) >= minPrecedence) {
		const string& op(ops[operatorIndex]);
		auto precedence = Syntax::BinaryOperatorsPrecedence.at(op);
		pos += op.size();
		auto right = ParsePrimary();
		while (StartsWithAny(statement, pos, ops, operatorIndex) &&
				Syntax::BinaryOperatorsPrecedence.at(ops[operatorIndex]) > precedence) {
			auto higherPrecedence = Syntax::BinaryOperatorsPrecedence.at(ops[operatorIndex]);
			right = ParsePartialExpression(right, higherPrecedence);
		}
		left = make_shared<NodeBinaryOperator>(left, binaryOperatorFactory->Create(op), right);
	}
	return left;
}
