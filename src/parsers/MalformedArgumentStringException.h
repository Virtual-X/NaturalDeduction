/*
 * MalformedArgumentStringException.h
 *
 *  Created on: Feb 3, 2014
 *      Author: igor
 */

#ifndef MALFORMEDARGUMENTSTRINGEXCEPTION_H_
#define MALFORMEDARGUMENTSTRINGEXCEPTION_H_

#include <exception>
#include <string>
using namespace std;

class MalformedArgumentStringException : public exception {
public:
	MalformedArgumentStringException(const string& message);
	virtual ~MalformedArgumentStringException();

	virtual const char* what() const throw();

private:
	string message;
};

#endif /* MALFORMEDARGUMENTSTRINGEXCEPTION_H_ */
