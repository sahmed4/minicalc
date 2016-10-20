#pragma once

#include <string>
#include <map>

class Treatment {
public:
	Treatment();
	explicit Treatment(const std::string &s);
	Treatment(const std::string &s, double a, double sample_size);

	~Treatment();

	//setters
	void setName(const std::string& nm);
	void setAlpha(double ap);
	void setN(double ss);

	//getters
	inline std::string getName() const;
	inline double getAlpha() const;
	inline double getBeta() const;
	inline double getN() const;

	//std::map<std::string, Treatment*> tmap();
	
private:
	std::string name;
	double alpha = 0.0;
	double n = 0.0;
};

double var(const Treatment& t);
double stddev(const Treatment& t);
double conv(const Treatment& t);
void print(const Treatment& t);
void header(const Treatment& t);
//std::map<std::string, Treatment> tmap();