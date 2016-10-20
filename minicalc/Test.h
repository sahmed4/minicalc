#pragma once

#include <vector>
#include <string>

#include "Treatment.h"

class Test {
public:
	Test();
	explicit Test(const std::string &s);
	Test(Treatment& t);
	Test(const std::string& s, Treatment& t);
	Test(const std::string& s, std::vector<Treatment>& v);
	~Test();

	//setters
	void setName(std::string& nm);

	//getters
	std::string getName() const;
	Treatment getTreatment(const std::string &s) const;
	std::vector<Treatment*> getTreatments() const;

private:
	std::string name;
	std::vector<Treatment*> treatments;
};

double phi(double x);
double zscore(Treatment& a, Treatment& b);
double pval(Treatment& a, Treatment& b);
double lbeta(double alpha, double beta);
double ab_bayes(Treatment &a, Treatment &b);
double abc_bayes(Treatment &a, Treatment &b, Treatment &c);
void print(const Test& t);
std::string str_tolower(std::string s);