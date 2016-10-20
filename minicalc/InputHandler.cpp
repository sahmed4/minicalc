#include "stdafx.h"
#include "InputHandler.h"
/*test*/
InputHandler::InputHandler() {
}


InputHandler::~InputHandler() {
}

void InputHandler::setCurMenu(Menu* menu) {
	cur_menu = menu;
}

void InputHandler::setParents(std::map<Menu*, Menu*> parent_menus) {
	parents = parent_menus;
}

void InputHandler::setChilds(std::map<Menu*, std::map<char, Menu*>> child_menus) {
	childs = child_menus;
}

Menu* InputHandler::getCurMenu() {
	return cur_menu;
}

char InputHandler::prompt(const std::string& s) {
	header(*cur_menu);
	char c = '\0';
	auto end = cur_menu->getOption().end();
	do {
		std::cout << s;
		std::cin >> c;
		if (c == '?') {
			print(*cur_menu);
			std::cout << std::endl;
		}
		else if (c == 'q')
			return c;
	} while (cur_menu->getOption().find(c) == end);
	return c;
}

Menu* InputHandler::launch(char c) {
	if (c == 'q') 
		return parents.find(cur_menu)->second;
	else if (childs.find(cur_menu)->second.find(c) != childs.find(cur_menu)->second.end()) 
		return childs.find(cur_menu)->second.find(c)->second;
	else 
		return cur_menu;
}

Menu* InputHandler::exit() {
	return parents.find(cur_menu)->second;
}

//Menu* InputHandler::launch(char c) {
//	if (cur_menu->child_menu.find(c) != cur_menu->child_menu.end())
//		return cur_menu->child_menu.find(c)->second;
//	else {
//		std::cout << "Not a valid selection." << std::endl;
//		return cur_menu;
//	}
//}

//Menu* InputHandler::run(Menu* active_menu) {
//	bool quit = 0;
//	while (!quit) {
//		active_menu = this->launch(prompt("Input selection (? for help): "));
//	}
//}