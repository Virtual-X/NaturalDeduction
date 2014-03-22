/*
 * BinaryOperatorFactory.cpp
 *
 *  Created on: Feb 7, 2014
 *      Author: igor
 */

#include "BinaryOperatorFactory.h"
#include "BinaryOperatorAnd.h"
#include "BinaryOperatorOr.h"
#include "BinaryOperatorImply.h"
#include "Syntax.h"

#include <set>
#include <assert.h>

BinaryOperatorFactory::BinaryOperatorFactory()
: createOperatorFromName{
	{ Syntax::And, [] { return make_shared<BinaryOperatorAnd>(); } },
	{ Syntax::Or, [] { return make_shared<BinaryOperatorOr>(); } },
	{ Syntax::Imply, [] { return make_shared<BinaryOperatorImply>(); } } }
{
	// my unit test
	assert(([&] {
		set<string> mapped;
		for (const auto& create : createOperatorFromName) {
			mapped.insert(create.first);
		}
		const set<string> binary(Syntax::BinaryOperators.begin(), Syntax::BinaryOperators.end());
		return mapped == binary; })());
}

BinaryOperatorFactory::~BinaryOperatorFactory() {
}

const vector<string>& BinaryOperatorFactory::GetOperators() const {
	return Syntax::BinaryOperators;
}

shared_ptr<BinaryOperator> BinaryOperatorFactory::Create(const string& operatorName) {
	return createOperatorFromName.at(operatorName)();
}
