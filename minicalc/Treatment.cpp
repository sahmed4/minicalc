#include "stdafx.h"
#include "Treatment.h"
#include <iostream>
#include <iomanip>

Treatment::Treatment() {}
Treatment::Treatment(const std::string &s) : name(s) {};
Treatment::Treatment(const std::string &s, double a, double sample_size) : name(s), alpha(a), n(sample_size) {}
Treatment::~Treatment() {}

//setters
void Treatment::setName(const std::string& nm) { name = nm; }
void Treatment::setAlpha(double ap) { alpha = ap; }
void Treatment::setN(double ss) { n = ss; }

//getters
std::string Treatment::getName() const { return name; }
double Treatment::getAlpha() const { return alpha; }
double Treatment::getBeta() const { return n - alpha; }
double Treatment::getN() const { return n; }

double var(const Treatment& t) {
	double alpha = t.getAlpha();
	double beta = t.getBeta();
	return (alpha * beta) / (pow(alpha + beta, 2) * (alpha + beta + 1));
}

double stddev(const Treatment& t) {
	return sqrt(var(t));
}

double conv(const Treatment& t) {
	return t.getAlpha() / t.getN();
}

void print(const Treatment& t) {
	std::cout 
		<< std::setw(12) << std::left << t.getName()
		<< std::setw(8) << std::right << std::fixed << std::setprecision(0) << t.getAlpha()
		<< std::setw(8) << std::right << std::fixed << std::setprecision(0) << t.getN()
		<< std::setw(8) << std::right << std::fixed << std::setprecision(2) << conv(t) * 100 << "%"
		<< std::setw(8) << std::right << std::fixed << std::setprecision(2) << stddev(t) * 100 << "%"
		<< std::endl;
}

void header(const Treatment& t) {
	std::cout
		<< std::setw(12) << std::left << "Variation"
		<< std::setw(8) << std::right << "alpha"
		<< std::setw(8) << std::right << "n"
		<< std::setw(8) << std::right << "conv %"
		<< std::setw(8) << std::right << "stddev"
		<< std::endl;
}

//std::map<std::string, Treatment*> Treatment::tmap() {
//	
//	std::map<std::string, Treatment*> t['a'] = { this };
//}

//std::map<std::string, Treatment&> tmap(const Treatment& t) {
//	std::map<std::string, Treatment&> t{ 
//		{t.getName(), t} 
//	};
//}