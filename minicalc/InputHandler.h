#pragma once

#include <string>
#include <map>
#include <vector>

#include "Menu.h"

class InputHandler {
public:
	InputHandler();
	InputHandler(Menu& main, std::map<Menu*, Menu*> p, std::map<Menu*, std::map<char, Menu*>> c) : 
		cur_menu(&main), parents(p), childs(c) {}

	//setters
	void setCurMenu(Menu* menu);
	void setParents(std::map<Menu*, Menu*> pt);
	void setChilds(std::map<Menu*, std::map<char, Menu*>>);

	//getters
	Menu* getCurMenu();

	Menu* launch(char c);
	Menu* exit();
	char prompt(const std::string& s);

	~InputHandler();

private:
	Menu* cur_menu = nullptr;
	std::map<Menu*, Menu*> parents;
	std::map<Menu*, std::map<char, Menu*>> childs;
};
