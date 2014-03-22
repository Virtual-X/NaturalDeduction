/*
 * Combinatorial.h
 *
 *  Created on: Feb 8, 2014
 *      Author: igor
 */

#ifndef COMBINATORIAL_H_
#define COMBINATORIAL_H_

#include <vector>
using namespace std;

class Combinatorial {
public:

	class Handler {
	public:
		virtual ~Handler() { }
		virtual void ElementChanged(size_t index, size_t value) = 0;
		virtual bool EvaluateElements(const vector<size_t>& values) = 0;
	};

	Combinatorial(size_t indicesCount, size_t valuesCount);
	virtual ~Combinatorial();

	void Enumerate(Handler& handler);

private:
	size_t valuesCount;
	vector<size_t> values;
	size_t index;
};

#endif /* COMBINATORIAL_H_ */
