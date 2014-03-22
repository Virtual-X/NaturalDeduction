/*
 * MalformedArgumentStringException.cpp
 *
 *  Created on: Feb 3, 2014
 *      Author: igor
 */

#include "MalformedArgumentStringException.h"

MalformedArgumentStringException::MalformedArgumentStringException(const string& message)
: message(message) {
}

MalformedArgumentStringException::~MalformedArgumentStringException() {
}

const char* MalformedArgumentStringException::what() const throw() {
	return message.c_str();
}
