/*
 * Value.h
 *
 *  Created on: Feb 8, 2014
 *      Author: igor
 */

#ifndef VALUE_H_
#define VALUE_H_

enum class Value {
	Undefined = -1,
	False = 0,
	True = 1
};

inline bool IsUndefined(Value value) {
	return value == Value::Undefined;
}

template<typename T>
T SwitchValue(Value value, T undefinedValue, T falseValue, T trueValue) {
	return value == Value::Undefined ? undefinedValue :
			(value == Value::True ? trueValue : falseValue);
}

#endif /* VALUE_H_ */
