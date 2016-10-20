// minicalc.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <map>
#include <string>

#include "InputHandler.h"
#include "Menu.h"
#include "Test.h"
#include "Treatment.h"


int main() {
	Menu menu_main(NAME_MAIN, OPTIONS_MAIN);
	Menu menu_config(NAME_CONFIG, OPTIONS_CONFIG);
	Menu menu_estimate(NAME_ESTIMATE, OPTIONS_ESTIMATE);
	Menu menu_estimate_change(NAME_ESTIMATE_CHANGE, OPTIONS_ESTIMATE_CHANGE);
	Menu menu_save(NAME_SAVE, OPTIONS_SAVE);
	Menu menu_write(NAME_WRITE);
	Menu menu_load(NAME_LOAD);
	Menu menu_quit(NAME_QUIT, OPTIONS_QUIT);
	Menu menu_force_quit(NAME_FORCE_QUIT);
	Menu menu_print(NAME_PRINT);

	const std::map<char, Menu*> CHILD_MAIN = {
		{ '!', &menu_force_quit },
		{ 'c', &menu_config },
		{ 'e', &menu_estimate },
		{ 'l', &menu_load },
		{ 'p', &menu_print },
		{ 'q', &menu_quit },
		{ 's', &menu_save },
		{ 'w', &menu_write },
	};

	const std::map<Menu*, Menu*> PARENTS = {
		{ &menu_main, &menu_quit },
		{ &menu_config, &menu_main },
		{ &menu_estimate, &menu_main },
		{ &menu_load, &menu_main },
		{ &menu_print, &menu_main },
		{ &menu_quit, &menu_main },
		{ &menu_save, &menu_main },
		{ &menu_write, &menu_main },
		{ &menu_force_quit, &menu_main }
	};

	const std::map<Menu*, std::map<char, Menu*>> CHILD_MAP = {
		{&menu_main, CHILD_MAIN}
	};

	InputHandler menus(menu_main, PARENTS, CHILD_MAP);
	bool quit = false;

	while (!quit) {
		char sel = menus.prompt("Input selection (? for help): ");
		Menu* cur_menu = menus.launch(sel);
		menus.setCurMenu(cur_menu);
	}

	return 0;
}














//Menu menu_main(NAME_MAIN, OPTIONS_MAIN);
//Menu menu_config(NAME_CONFIG, OPTIONS_CONFIG);
//Menu menu_estimate(NAME_ESTIMATE, OPTIONS_ESTIMATE);
//
//const std::map<char, Menu*> CHILD_MAIN{
//	{ 'c', &menu_config }
//};
//
//Treatment t1("t1", 1243, 23532);
//Treatment t2("t2", 1279, 23532);
//Treatment t3("t3", 1329, 23532);
//std::cout << ab_bayes(t1, t2) << std::endl;
//Test sometest("sometest", t1);
//header(t1);
////print(sometest.getTreatment("long test name more"));
//print(sometest);
//
//t1.setAlpha(1492);
////print(sometest.getTreatment("long test name more"));
//print(sometest);
//
//t1.setName("test");
////print(sometest.getTreatment("long test name more"));
//print(sometest);
//
////Menu p("test", { {'c',"char" }, { 't',"test" } });
//Menu exit, child("child"), test;
//Menu parent;
//std::string mm = "Main Menu";
//
//std::map<char, std::string> options_main{
//	{ 'c',"configure tests and view results" },
//	{ 'e',"estimate test length" },
//	{ 'l',"load from loadable file" },
//	{ 'p',"save results to file" },
//	{ 'q',"quit" },
//	{ 'w',"write to loadable file" },
//	{ '!',"quit without saving" },
//};
//std::map<char, Menu*> main_child{ { 'x', &exit },{ 'c', &child },{ 't', &test } };
//
///*Menu main(mm, parent, options_main, main_child);*/
//
////print(main);
//
//child.setName("Child Menu");
//child.setOption('x', "exit");
//std::cout << std::endl;
////char sel = prompt(main,"Input selection (? for help): ");
////print(main.launch(std::cin));
///*prompt(main.launch(prompt(main, "Input selection (? for help): ")), "Input selection (? for help): ");*/
//child.setOption('n', "new");
//std::cout << std::endl;
