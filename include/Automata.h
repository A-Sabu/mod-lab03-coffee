// Copyright 2025 A-Sabu
#pragma once
#include <iostream>
#include <vector>
#include <string>

class Automata {
 public:
    Automata(std::vector<std::string> menu, std::vector<float> prices);
    void on();
    void off();
    void coin(float cash_now);
    std::vector<std::string> getMenu();
    void printMenu();
    std::string getState();
    void choice(int user_choice);
    void check();
    void cancel();
    void cook();
    void finish();
    float giveChange();
 private:
    enum STATES {OFF, WAIT, ACCEPT, CHECK, COOK};
    float _cash;
    std::vector<std::string> _menu;
    std::vector<float> _prices;
    STATES _state;
    float _user_cash;
    int _user_choice;
};
