/*
 * Combinatorial.cpp
 *
 *  Created on: Feb 8, 2014
 *      Author: igor
 */

#include "Combinatorial.h"

Combinatorial::Combinatorial(size_t indicesCount, size_t valuesCount)
: valuesCount(valuesCount),
  values(indicesCount),
  index(0) {
}

Combinatorial::~Combinatorial() {
}

void Combinatorial::Enumerate(Handler& handler) {
	for (size_t i = 0; i < values.size(); i++) {
		handler.ElementChanged(i, values[i]);
	}
	if (!handler.EvaluateElements(values)) {
		return;
	}
	while (index < values.size()) {
		values[index]++;
		if (values[index] == valuesCount) {
			values[index] = 0;
			handler.ElementChanged(index, values[index]);
			index++;
		} else {
			handler.ElementChanged(index, values[index]);
			if (!handler.EvaluateElements(values)) {
				return;
			}
			index = 0;
		}
	}
}
