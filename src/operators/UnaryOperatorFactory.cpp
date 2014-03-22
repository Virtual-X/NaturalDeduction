/*
 * UnaryOperatorFactory.cpp
 *
 *  Created on: Feb 7, 2014
 *      Author: igor
 */

#include "UnaryOperatorFactory.h"
#include "UnaryOperatorNegation.h"
#include "Syntax.h"

#include <set>
#include <assert.h>

UnaryOperatorFactory::UnaryOperatorFactory()
: createOperatorFromName{
	{ Syntax::Negation, [] { return shared_ptr<UnaryOperator>(new UnaryOperatorNegation()); } } }
{
	// my unit test
	assert(([&] {
		set<string> mapped;
		for (const auto& create : createOperatorFromName) {
			mapped.insert(create.first);
		}
		const set<string> binary(Syntax::UnaryOperators.begin(), Syntax::UnaryOperators.end());
		return mapped == binary; })());
}

UnaryOperatorFactory::~UnaryOperatorFactory() {
}

const vector<string>& UnaryOperatorFactory::GetOperators() const {
	return Syntax::UnaryOperators;
}

shared_ptr<UnaryOperator> UnaryOperatorFactory::Create(const string& operatorName) {
	return (createOperatorFromName.find(operatorName)->second)();
}
