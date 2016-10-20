#include "stdafx.h"
#include "Test.h"

#include <iostream>
#include <iomanip>
#include <cmath>

Test::Test() {}
Test::Test(const std::string &s) : name(s) {}
Test::Test(Treatment& t) {
	treatments.push_back(&t);
}Test::Test(const std::string &s, Treatment &t) : name(s) {
	treatments.push_back(&t);
}
Test::Test(const std::string& s, std::vector<Treatment>& v) : name(s) {
	for (Treatment& t : v)
		treatments.push_back(&t);
}
Test::~Test() {}

void Test::setName(std::string& nm) { name = nm; }

std::string Test::getName() const {
	return name;
}

Treatment Test::getTreatment(const std::string& s) const {
	for (const auto& a : treatments) {
		if (str_tolower(a->getName()) == str_tolower(s))
			return *a;
	}
	return Treatment();
}

std::vector<Treatment*> Test::getTreatments() const {
	return treatments;
}

double phi(double x) {
	constexpr double P = 0.327591;
	constexpr double A1 = 0.254829592;
	constexpr double A2 = -0.284496736;
	constexpr double A3 = 1.421413741;
	constexpr double A4 = -1.453152027;
	constexpr double A5 = 1.061405429;

	int sign = 1;
	if (x < 0)
		sign = -1;
	x = fabs(x) / sqrt(2.0);

	double t = 1.0 / (1.0 + P*x),
		y = 1.0 - (((((A5*t + A4)*t) + A3)*t + A2)*t + A1)*t*exp(-x*x);

	return 0.5*(1.0 + sign*y);
}

double zscore(Treatment& a, Treatment& b) {
	double convA = conv(a);
	double convB = conv(b);
	return (convB - convA) / sqrt((convB * (1 - convB) / b.getN()) + (convA * (1 - convA) / a.getN()));
}

double pval(Treatment& a, Treatment& b) {
	return (1 - phi(fabs(zscore(a, b)))) * 2;
}

double lbeta(double alpha, double beta) {
	return lgamma(alpha) + lgamma(beta) - lgamma(alpha + beta);
}

//probability that b beats a
double ab_bayes(Treatment &a, Treatment &b) {
	double total = 0.0;
	double alpha_a = a.getAlpha(), beta_a = a.getBeta();
	double alpha_b = b.getAlpha(), beta_b = b.getBeta();

	for (int i = 0; i <= alpha_b - 1; ++i)
		total +=
		exp(
			lbeta(alpha_a + i, beta_b + beta_a)
			- log(beta_b + i)
			- lbeta(1 + i, beta_b)
			- lbeta(alpha_a, beta_a)
		);
	
	return total;
}

//probability that c beats a and b (slow)
double abc_bayes(Treatment &a, Treatment &b, Treatment &c) {
	double total = 0.0;
	double alpha_a = a.getAlpha(), beta_a = a.getBeta();
	double alpha_b = b.getAlpha(), beta_b = b.getBeta();
	double alpha_c = c.getAlpha(), beta_c = c.getBeta();

	for (int i = 0; i <= alpha_a - 1; ++i) {
		for (int j = 0; j <= alpha_b - 1; ++j)
			total +=
			exp(
				lbeta(alpha_c + i + j, beta_a + beta_b + beta_c)
				- log(beta_a + i)
				- log(beta_b + j)
				- lbeta(1 + i, beta_a)
				- lbeta(1 + j, beta_b)
				- lbeta(alpha_c, beta_c)
			);
	}

	return 1 - ab_bayes(c, a) - ab_bayes(c, b) + total;
}


void print(const Test& t) {
	std::vector<Treatment*> treatments = t.getTreatments();
	for (auto a : treatments) {
		std::cout << std::setw(12) << std::left << t.getName();
		print(*a);
	}
}

std::string str_tolower(std::string s) {
	for (auto& c : s)
		c = tolower(c);
	return s;
}