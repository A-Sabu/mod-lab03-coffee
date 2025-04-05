#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Automata {
public:
	Automata(float cash, vector<string> menu, vector<float> prices);
	void on();
	void off();
	void coin();
	void etMenu();
	void getState();
	void choice();
	void check();
	void cancel();
	void cook();
	void finish();
private:
	enum STATES {
		OFF,
		WAIT,
		ACCEPT,
		CHECK,
		COOK
	};
	float _cash;
	vector<string> _menu;
	vector<float> _prices;
	STATES _state;
};