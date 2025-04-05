#pragma once
#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
using namespace std;

class Automata {
public:
	Automata(vector<string> menu, vector<float> prices);
	void on();
	void off();
	void coin(float cash_now);
	vector<string> getMenu();
	void printMenu();
	auto getState();
	void choice(int user_choice);
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
	float _user_cash;
	int _user_choice;
	float giveСhange();
};
