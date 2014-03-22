/*
 * StringFunctions.h
 *
 *  Created on: Feb 8, 2014
 *      Author: igor
 */

#ifndef STRINGFUNCTIONS_H_
#define STRINGFUNCTIONS_H_

#include <string>
#include <vector>
using namespace std;

bool StartsWith(const string& str, size_t pos, const string& prefix);
bool StartsWithAny(const string& str, size_t pos, const vector<string>& prefixes, size_t& prefixIndex);
void EraseBegin(string& str, size_t size);
vector<string> Split(const string& str, const string& separator);
size_t FindFirst(const string& str, size_t offset, const vector<string>& separators, size_t& separatorIndex);
vector<string> Split(const string& str, const vector<string>& separators, vector<string>& separatorsFound);
void EraseAllOccurrencies(string& str, const string& substr);

#endif /* STRINGFUNCTIONS_H_ */
