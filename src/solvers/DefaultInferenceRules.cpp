/*
 * DefaultInferenceRules.cpp
 *
 *  Created on: Feb 12, 2014
 *      Author: igor
 */

#include "DefaultInferenceRules.h"
#include "InferenceRule.h"

DefaultInferenceRules::DefaultInferenceRules(VariablesContainer& variables)
: variables(variables) {
	AddAllRules();
}

DefaultInferenceRules::~DefaultInferenceRules() {
}

const vector<InferenceRule>& DefaultInferenceRules::GetInferenceRules() const {
	return rules;
}

void DefaultInferenceRules::Add(const string& name, const string& argument, const string& description) {
	rules.push_back(InferenceRule(name, description, argument, variables));
}

void DefaultInferenceRules::AddAllRules() {
	// http://en.wikipedia.org/wiki/Propositional_calculus#Basic_and_derived_argument_forms
	Add("Modus Ponens", "((p -> q) ^ p) // q", "If p then q; p; therefore q");
	Add("Modus Tollens", "((p -> q) ^ ~q) // ~p", "If p then q; not q; therefore not p");
	Add("Hypothetical Syllogism", "((p -> q) ^ (q -> r)) // (p -> r)", "If p then q; if q then r; therefore, if p then r");
	Add("Disjunctive Syllogism", "((p V q) ^ ~p) // q", "Either p or q, or both; not p; therefore, q");
	Add("Constructive Dilemma", "((p -> q) ^ (r -> s) ^ (p V r)) // (q V s)", "If p then q; and if r then s; but p or r; therefore q or s");
	Add("Destructive Dilemma", "((p -> q) ^ (r -> s) ^ (~q V ~s)) // (~p V ~r)", "If p then q; and if r then s; but not q or not s; therefore not p or not r");
	Add("Bidirectional Dilemma", "((p -> q) ^ (r -> s) ^ (p V ~s)) // (q V ~r)", "If p then q; and if r then s; but p or not s; therefore q or not r");
	Add("Simplification", "(p ^ q) // p", "p and q are true; therefore p is true");
	Add("Conjunction", "p,q // (p ^ q)", "p and q are true separately; therefore they are true conjointly");
	Add("Addition", "p // (p V q)", "p is true; therefore the disjunction (p or q) is true");
	Add("Composition", "((p -> q) ^ (p -> r)) // (p -> (q ^ r))", "If p then q; and if p then r; therefore if p is true then q and r are true");
	Add("De Morgan's Theorem (1)", "~(p ^ q) // (~p V ~q)", "The negation of (p and q) is equiv. to (not p or not q)");
	Add("De Morgan's Theorem (2)", "~(p V q) // (~p ^ ~q)", "The negation of (p or q) is equiv. to (not p and not q)");
	Add("Commutation (1)", "(p V q) // (q V p)", "(p or q) is equiv. to (q or p)");
	Add("Commutation (2)", "(p ^ q) // (q ^ p)", "(p and q) is equiv. to (q and p)");
	Add("Commutation (3)", "(p <-> q) // (q <-> p)", "(p is equiv. to q) is equiv. to (q is equiv. to p)");
	Add("Association (1)", "(p V (q V r)) // ((p V q) V r)", "p or (q or r) is equiv. to (p or q) or r");
	Add("Association (2)", "(p ^ (q ^ r)) // ((p ^ q) ^ r)", "p and (q and r) is equiv. to (p and q) and r");
	Add("Distribution (1)", "(p ^ (q V r)) // ((p ^ q) V (p ^ r))", "p and (q or r) is equiv. to (p and q) or (p and r)");
	Add("Distribution (2)", "(p V (q ^ r)) // ((p V q) ^ (p V r))", "p or (q and r) is equiv. to (p or q) and (p or r)");
	Add("Double Negation", "p // ~~p", "p is equivalent to the negation of not p");
	Add("Transposition", "(p -> q) // (~q -> ~p)", "If p then q is equiv. to if not q then not p");
	Add("Material Implication", "(p -> q) // (~p V q)", "If p then q is equiv. to not p or q");
	Add("Material Equivalence (1)", "(p <-> q) // ((p -> q) ^ (q -> p))", "(p iff q) is equiv. to (if p is true then q is true) and (if q is true then p is true)");
	Add("Material Equivalence (2)", "(p <-> q) // ((p ^ q) V (~p ^ ~q))", "(p iff q) is equiv. to either (p and q are true) or (both p and q are false)");
	Add("Material Equivalence (3)", "(p <-> q) // ((p V ~q) ^ (~p V q))", "(p iff q) is equiv to., both (p or not q is true) and (not p or q is true)");
	Add("Exportation[9]", "((p ^ q) -> r) // (p -> (q -> r))", "from (if p and q are true then r is true) we can prove (if q is true then r is true, if p is true)");
	Add("Importation", "(p -> (q -> r)) // ((p ^ q) -> r)", "If p then (if q then r) is equivalent to if p and q then r");
	Add("Tautology (1)", "p // (p V p)", "p is true is equiv. to p is true or p is true");
	Add("Tautology (2)", "p // (p ^ p)", "p is true is equiv. to p is true and p is true");
	Add("Tertium non datur (Law of Excluded Middle)", " // (p V ~p)", "p or not p is true");
	Add("Law of Non-Contradiction", " // ~(p ^ ~p)", "p and not p is false, is a true statement");
}
