// minicalc.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <map>
#include <string>

#include "Menu.h"
#include "Treatment.h"
#include "Test.h"

int main() {
	Treatment t1("t1", 1243, 23532);
	Treatment t2("t2", 1279, 23532);
	Treatment t3("t3", 1329, 23532);
	std::cout << ab_bayes(t1,t2) << std::endl;
	Test sometest("sometest", t1);
	header(t1);
	//print(sometest.getTreatment("long test name more"));
	print(sometest);
	
	t1.setAlpha(1492);
	//print(sometest.getTreatment("long test name more"));
	print(sometest);

	t1.setName("test");
	//print(sometest.getTreatment("long test name more"));
	print(sometest);

	//Menu p("test", { {'c',"char" }, { 't',"test" } });
	Menu exit, child("child"), test;
	Menu parent;
	std::string mm = "Main Menu";

	std::map<char, std::string> options_main{
		{'c',"configure tests and view results"},
		{'e',"estimate test length"},
		{'l',"load from loadable file"},
		{'p',"save results to file"},
		{'q',"quit"},
		{'w',"write to loadable file"},
		{'!',"quit without saving"},
	};
	std::map<char, Menu*> main_child{ { 'x', &exit },{ 'c', &child },{ 't', &test } };

	Menu main(mm, parent, options_main, main_child);

	//print(main);

	child.setName("Child Menu");
	child.setOption('x', "exit");
	std::cout << std::endl;
	char sel = prompt(main,"Input selection (? for help): ");
	//print(main.launch(std::cin));
	main.launch(sel);
	child.setOption('n', "new");
	std::cout << std::endl;

	return 0;
}