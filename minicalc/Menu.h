#pragma once
#include <string>
#include <map>
#include <iostream>

class Menu {
public:
	friend char prompt(Menu& m, const std::string& s);
	//constructors
	Menu();
	Menu(const std::string &n);
	Menu(const std::string &n, Menu &pm);
	Menu(const std::string &n, Menu &pm, const std::map<char, std::string> &m);
	Menu(const std::string &n, const std::map<char, std::string> &m);
	Menu(const std::string &n, const std::map<char, std::string> &m, std::map<char, Menu*> &cm);
	Menu(const std::string &n, Menu &pm, const std::map<char, std::string> &m, std::map<char, Menu*> &cm);

	void init(const std::string &n, Menu &pm, const std::map<char, std::string> &m, std::map<char, Menu*> &cm);
	void display();
	Menu* exit();
	Menu& launch(std::istream &is);
	Menu launch(char c);

	//setters
	void setName(const std::string& nm);
	void setOption(const char c, const std::string& s);
	void setOption(const std::map<char, std::string> &m);
	void setParent(Menu& pm);
	void setChild(const char c, Menu& cm);
	void setChild(const std::map<char, Menu*> &cm);

	//getters
	inline std::string getName() const;
	inline std::map<char, std::string> getOption() const;
	std::string getOption(const char c) const;

	//destructors
	~Menu();

private:
	std::string name;
	std::map<char, std::string> options;
	Menu* parent_menu = nullptr;
	std::map<char, Menu*> child_menu;
};

void print(Menu &m);
void header(Menu &m);
char prompt(Menu& m, const std::string& s);

const std::string NAME_CONFIG = "Configure Tests and View Results";
const std::string NAME_ESTIMATE = "Estimate Tests";
const std::string NAME_LOAD = "Load from File";
const std::string NAME_SAVE = "Save Results";
const std::string NAME_QUIT = "Quit";
const std::string NAME_WRITE = "Write to Loadable File";
const std::string NAME_MAIN = "Main Menu";

const std::map<char, std::string> OPTIONS_MAIN{
	{ '!',"quit without saving" },
	{ 'c',"configure tests and view results" },
	{ 'e',"estimate test length" },
	{ 'l',"load from loadable file" },
	{ 'p',"print results" },
	{ 'q',"quit" },
	{ 's',"save results to file" },
	{ 'w',"write to loadable file" },
};

const std::map<char, std::string> OPTIONS_CONFIG{
	{ 'a',"add test" },
	{ 'c',"add treatment" },
	{ 'l',"load from loadable file" },
	{ 's',"save results to file" },
	{ 'q',"quit to previous menu" }
};

const std::map<char, std::string> OPTIONS_ESTIMATE{
	{ 'r',"restart estimate" },
	{ 'q',"quit to previous menu" }
};

const std::map<char, Menu*> CHILD_MAIN{
	{ 'c', &OPTIONS_CONFIG }
};