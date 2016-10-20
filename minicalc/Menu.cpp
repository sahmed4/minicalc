#include "stdafx.h"
#include "Menu.h"
#include <iostream>
#include <string>

//constructors
Menu::Menu() {}
Menu::Menu(const std::string &n) : name(n) {}
Menu::Menu(const std::string &n, const std::map<char, std::string> &m) : name(n), options(m) {}

//member functions
void Menu::init(const std::string &n, const std::map<char, std::string> &m) {
	name = n; 
	options = m;
}

void Menu::display() {
	for (const auto &it : options)
		std::cout << it.first << "\t" << it.second << std::endl;
}

//setters
void Menu::setName(const std::string& n) { name = n; }

void Menu::setOption(const char c, const std::string& s) { 
	options[c] = s;
}

void Menu::setOption(const std::map<char, std::string> &m) {
	options = m;
}

//getters
std::string Menu::getName() const { return name; }

std::map<char, std::string>& Menu::getOption() {
	return options;
}

std::string Menu::getOption(const char c) const {
	if (options.find(c) != options.end())
		return options.find(c)->second;
	else
		return "No value";
}

//free functions
void header(Menu &m) {
	std::cout << "----------------------------------------\n";
	std::cout << m.getName() << "\n";
	std::cout << "----------------------------------------\n";
}

void print(Menu &m) {
	std::map<char, std::string> options = m.getOption();
	for (const auto &it : options)
		std::cout << it.first << ":\t" << it.second << std::endl;
}

//destructors
Menu::~Menu() {}

//char prompt(Menu& m, const std::string& s) {
//	header(m);
//	char c = '\0';
//	auto end = m.options.end();
//	do {
//		std::cout << s;
//		std::cin >> c;
//		if (c == '?') {
//			print(m);
//			std::cout << std::endl;
//		}
//	} while (m.options.find(c) == end);
//	return c;
//}

//Menu::Menu(const std::string &n, Menu &pm) : name(n), parent_menu(&pm) {}
//Menu::Menu(const std::string &n, Menu &pm, const std::map<char, std::string> &m) :
//	name(n), parent_menu(&pm), options(m) {}
//Menu::Menu(const std::string &n, const std::map<char, std::string> &m, std::map<char, Menu*> &cm) :
//	name(n), options(m), child_menu(cm) {}
//Menu::Menu(const std::string &n, Menu &pm, const std::map<char, std::string> &m, std::map<char, Menu*> &cm) :
//	name(n), parent_menu(&pm), options(m), child_menu(cm) {}

//Menu* Menu::exit() {
//	return parent_menu;
//}
//
//Menu* Menu::launch(std::istream &is) {
//	char c;
//	is >> c;
//	if (child_menu.find(c) != child_menu.end())
//		return child_menu.find(c)->second;
//	else {
//		std::cout << "Not a valid selection." << std::endl;
//		return this;
//	}
//}
//
//Menu* Menu::launch(char c) {
//	if (child_menu.find(c) != child_menu.end())
//		return child_menu.find(c)->second;
//
//	else {
//		std::cout << "Not a valid selection." << std::endl;
//		return this;
//	}
//}

//char prompt(const Menu& m, const std::string& s) {
//	char c = '\0';
//	/*auto end = m.getOption().end();*/
//	do {
//		std::cout << s;
//		std::cin >> c;
//	} while (m.getOption().find(c) == m.getOption().end());
//	return c;
//}

//void Menu::setParent(Menu& pm) {
//	parent_menu = &pm;
//}
//
//void Menu::setChild(const char c, Menu& cm) {
//	child_menu[c] = &cm;
//}
//
//void Menu::setChild(const std::map<char, Menu*> &cm) {
//	child_menu = cm;
//}