/*
 * StringFunctions.cpp
 *
 *  Created on: Feb 8, 2014
 *      Author: igor
 */

#include "StringFunctions.h"

bool StartsWith(const string& str, size_t pos, const string& prefix) {
	return str.size() >= pos + prefix.size() && str.compare(pos, prefix.size(), prefix) == 0;
}

bool StartsWithAny(const string& str, size_t pos, const vector<string>& prefixes, size_t& prefixIndex) {
	prefixIndex = 0;
	for (const auto& p : prefixes) {
		if (StartsWith(str, pos, p)) {
			return true;
		}
		prefixIndex++;
	}
	return false;
}

void EraseBegin(string& str, size_t size) {
	str.erase(str.begin(), str.begin() + size);
}

vector<string> Split(const string& str, const string& separator) {
	vector<string> strings;
	size_t begin = 0;
	auto pos = str.find(separator);
	while (pos != string::npos) {
		strings.push_back(str.substr(begin, pos - begin));
		begin = pos + separator.size();
		pos = str.find(separator, begin);
	}
	if (begin < str.size()) {
		strings.push_back(str.substr(begin));
	}
	return strings;
}

size_t FindFirst(const string& str, size_t offset, const vector<string>& separators, size_t& separatorIndex) {
	size_t firstPos = string::npos;
	size_t i = 0;
	for (const auto& s : separators) {
		auto pos = str.find(s, offset);
		if (pos != string::npos && (firstPos == string::npos || pos < firstPos)) {
			firstPos = pos;
			separatorIndex = i;
		}
		i++;
	}
	return firstPos;
}

vector<string> Split(const string& str, const vector<string>& separators, vector<string>& separatorsFound) {
	vector<string> strings;
	size_t begin = 0;
	size_t separatorIndex;
	auto pos = FindFirst(str, 0, separators, separatorIndex);
	while (pos != string::npos) {
		strings.push_back(str.substr(begin, pos - begin));
		begin = pos + separators[separatorIndex].size();
		pos = FindFirst(str, begin, separators, separatorIndex);
	}
	if (begin < str.size()) {
		strings.push_back(str.substr(begin));
	}
	return strings;
}

void EraseAllOccurrencies(string& str, const string& substr) {
	auto pos = str.find(substr);
	while (pos != string::npos) {
		str.erase(pos, substr.size());
		pos = str.find(substr);
	}
}
