#include "Automata.h"

Automata::Automata(vector<string> menu, vector<float> prices) :
	_cash(0), _menu(menu), _prices(prices), _state(OFF), _user_cash(0), _user_choice(-1) {}

void Automata::on() {
	if (_state == OFF) {
		_state = WAIT;
		printMenu();

	} else {
		cout << "> Denied execution" << endl;
	}
};
void Automata::off() {
	if (_state == WAIT) {
		_state = OFF;

	} else {
		cout << "> Denied execution" << endl;
	}
};
void Automata::coin(float cash_now){
	if (_state == WAIT or _state == ACCEPT) {
		_state = ACCEPT;
		_user_cash += cash_now;
	} else {
		cout << "> Denied execution" << endl;
	}
};

vector<string> Automata::getMenu() {
	return _menu;
};

void Automata::printMenu() {
	cout << "> Menu:" << endl;
	for (int i = 0; i < _menu.size(); i++) {
		cout << i << ". [" << _menu[i] << "] - " << _prices[i] << "$" << endl;
	}
}

auto Automata::getState() {
	return _state;
};

void Automata::choice(int user_choice) {
	if (_state == ACCEPT) {
		if (0 <= user_choice and user_choice < _menu.size()) {
			_user_choice = user_choice;
			_state = CHECK;

		} else {
			cout << "> Uncorrect index" << endl;
		}

	} else {
		cout << "> Denied execution" << endl;
	}
};
void Automata::check() {
	if (_state == CHECK) {
		if (_prices[_user_choice] <= _user_cash) {
			cout << "> Check done" << endl;
			cook();

		} else {
			cout << "> There is not enough money" << endl;
			cancel();
		}

	} else {
		cout << "> Denied execution" << endl;
	}
};
void Automata::cancel() {
	if (_state == ACCEPT or _state == CHECK) {
		giveСhange();
		_state = WAIT;
		printMenu();

	} else {
		cout << "> Denied execution" << endl;
	}
};
void Automata::cook() {
	if (_state == CHECK) {
		_state = COOK;
		cout << "> Start cooking" << endl;
		this_thread::sleep_for(std::chrono::seconds(10));
		cout << "> Finish cooking" << endl;
		finish();

	} else {
		cout << "> Denied execution" << endl;
	}
};
void Automata::finish() {
	if (_state == COOK) {
		_cash += _user_cash - _prices[_user_choice];
		giveСhange();
		_state = WAIT;

	} else {
		cout << "> Denied execution" << endl;
	}
};
float Automata::giveСhange() {
	float change = _user_cash;
	_user_cash = 0;
	_user_choice = -1;
	return change;
};
