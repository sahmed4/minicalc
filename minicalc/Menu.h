#pragma once
#include <string>
#include <map>
#include <iostream>

class Menu {
	//friend class InputHandler;

public:
	friend char prompt(Menu& m, const std::string& s);
	//constructors
	Menu();
	explicit Menu(const std::string &n);
	Menu(const std::string &n, const std::map<char, std::string> &m);

	//member functions
	void init(const std::string &n, const std::map<char, std::string> &m);
	void display();
	
	//setters
	void setName(const std::string& nm);
	void setOption(const char c, const std::string& s);
	void setOption(const std::map<char, std::string> &m);

	//getters
	inline std::string getName() const;
	inline std::map<char, std::string>& getOption();
	std::string getOption(const char c) const;

	//destructors
	~Menu();

	//Menu(const std::string &n, Menu &pm);
	//Menu(const std::string &n, Menu &pm, const std::map<char, std::string> &m);
	//Menu(const std::string &n, const std::map<char, std::string> &m, std::map<char, Menu*> &cm);
	//Menu(const std::string &n, Menu &pm, const std::map<char, std::string> &m, std::map<char, Menu*> &cm);
	/*Menu* exit();
	Menu* launch(std::istream &is);
	Menu* launch(char c);*/
	/*void setParent(Menu& pm);
	void setChild(const char c, Menu& cm);
	void setChild(const std::map<char, Menu*> &cm);*/

private:
	std::string name;
	std::map<char, std::string> options;
	/*Menu* parent_menu = nullptr;
	std::map<char, Menu*> child_menu;*/
};

void print(Menu &m);
void header(Menu &m);
//char prompt(Menu& m, const std::string& s);

const std::string NAME_ESTIMATE = "Estimate Tests";
const std::string NAME_ESTIMATE_CHANGE = "Estimate Tests > Change Values";
const std::string NAME_SAVE = "Save Results";
const std::string NAME_WRITE = "Write to Loadable File";
const std::string NAME_LOAD = "Load from File";
const std::string NAME_CONFIG = "Configure Tests and View Results";
const std::string NAME_QUIT = "Quit";
const std::string NAME_MAIN = "Main Menu";
const std::string NAME_PRINT = "Print Results";
const std::string NAME_FORCE_QUIT = "Quit Without Saving";

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
	{ 'q',"quit to main menu" }
};

const std::map<char, std::string> OPTIONS_ESTIMATE{
	{ 'a', "add values" },
	{ 'c', "change values" },
	{ 'p', "print estimate" },
	{ 'r',"restart estimate" },
	{ 'q',"quit to main menu" }
};

const std::map<char, std::string> OPTIONS_ESTIMATE_CHANGE{
	{ 'c', "conversion (higher = faster)" },
	{ 'l', "expected lift (larger = faster)" },
	{ 't', "daily traffic (higher = faster)" },
	{ 'q', "back to estimate tests" }
};

const std::map<char, std::string> OPTIONS_QUIT{
	{ '!', "quit without saving" },
	{ 'y', "quit and save to default_loadable.csv" },
	{ 'q', "back to main menu" }
};

const std::map<char, std::string> OPTIONS_SAVE{
	{ 's', "select file name and save" },
	{ 'y', "quit and save to default_loadable.csv" },
	{ 'q', "back to main menu" }
};