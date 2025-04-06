// Copyright 2025 A-Sabu
#include "Automata.h"
#include <iostream>
#include <vector>
#include <string>

Automata::Automata(std::vector<std::string> menu, std::vector<float> prices) :
_cash(0),
_menu(menu),
_prices(prices),
_state(OFF),
_user_cash(0),
_user_choice(-1) {
}

void Automata::on() {
        if (_state == OFF) {
                _state = WAIT;
                printMenu();
        } else {
                std::cout << "> Denied execution" << std::endl;
        }
}
void Automata::off() {
        if (_state == WAIT) {
                _state = OFF;
        } else {
                std::cout << "> Denied execution" << std::endl;
        }
}
void Automata::coin(float cash_now) {
        if (_state == WAIT || _state == ACCEPT) {
                _state = ACCEPT;
                _user_cash += cash_now;
        } else {
                std::cout << "> Denied execution" << std::endl;
        }
}
std::vector<std::string> Automata::getMenu() {
        return _menu;
}
void Automata::printMenu() {
        std::cout << "> Menu:" << std::endl;
        for (int i = 0; i < _menu.size(); i++) {
                std::cout << i << ". [" << _menu[i] << "] - ";
                std::cout << _prices[i] << "$" << std::endl;
        }
}
std::string Automata::getState() {
        std::string string_state;
        switch (_state) {
        case OFF:
        string_state = "OFF";
        break;
        case WAIT:
        string_state = "WAIT";
        break;
        case ACCEPT:
        string_state = "ACCEPT";
        break;
        case CHECK:
        string_state = "CHECK";
        break;
        case COOK:
        string_state = "COOK";
        break;
        default:
        string_state = "UNKNOWN";
        break;
        }
        return string_state;
}
void Automata::choice(int user_choice) {
        if (_state == ACCEPT) {
                if (0 <= user_choice && user_choice < _menu.size()) {
                        _user_choice = user_choice;
                        _state = CHECK;
                } else {
                        std::cout << "> Uncorrect index" << std::endl;
                }
        } else {
                std::cout << "> Denied execution" << std::endl;
        }
}
void Automata::check() {
        if (_state == CHECK) {
                if (_prices[_user_choice] <= _user_cash) {
                        std::cout << "> Check done" << std::endl;
                        cook();
                } else {
                        std::cout << "> There is not enough money" << std::endl;
                        cancel();
                }
        } else {
                std::cout << "> Denied execution" << std::endl;
        }
}
void Automata::cancel() {
        if (_state == ACCEPT || _state == CHECK) {
                giveChange();
                _state = WAIT;
                printMenu();
        } else {
                std::cout << "> Denied execution" << std::endl;
        }
}
void Automata::cook() {
        if (_state == CHECK) {
                _state = COOK;
                std::cout << "> Start cooking" << std::endl;
                std::cout << "> Finish cooking" << std::endl;
                finish();
        } else {
                std::cout << "> Denied execution" << std::endl;
        }
}
void Automata::finish() {
        if (_state == COOK) {
                _cash += _user_cash - _prices[_user_choice];
                giveChange();
                _state = WAIT;
        } else {
                std::cout << "> Denied execution" << std::endl;
        }
}
float Automata::giveChange() {
        float change = _user_cash;
        _user_cash = 0;
        _user_choice = -1;
        return change;
}
