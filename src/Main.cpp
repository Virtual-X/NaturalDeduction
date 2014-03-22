//============================================================================
// Name        : NaturalDeduction.cpp
// Author      : Igor Beati
// Version     :
// Copyright   : @IB2014
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Argument.h"
#include "MalformedArgumentStringException.h"

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int Test(const string& argument) {
	Argument a;
	try {
		a = Argument(argument);
	} catch (MalformedArgumentStringException& ex) {
		cout << ex.what();
		return 1;
	}

	cout << endl << argument << endl;
	a.PrintVariables(cout);
	a.PrintStatements(cout);
	a.PrintConclusion(cout);

	a.PrintValidation(cout, false);

	cout << " --> " << (a.IsValid() ? "VALID!" : "NOT VALID!") << endl;

	a.DeduceConclusion();
	a.PrintDeductions(cout);
	cout << endl;
	return 0;
}

static const vector<string> tests{
	"(a^b)Vc//(aVb)^(aVc)",
	"a^(bVc)//bVc",
	"a->bVc->dtt//(a->(bVc))->dtt",
	"~~a/b//~(a^b)",
	"p->q/rVs/~s->~t/~qVs/~s/~pVr->u/wVt//u^w"
};

int main() {
	cout << "Please enter the argument, e.g. ~pVq/T->r/r^s/s^F//p->~s," << endl;
	cout << "       spaces are ignored, reserved keys are / ~ -> // V ^ T F ( )" << endl;
	cout << "Leave empty to run unit tests." << endl;
	string argument;
	getline(cin, argument);
	if (!argument.empty()) {
		Test(argument);
	} else {
		for (const auto& t : tests) {
			Test(t);
		}
	}

	return 0;
}
