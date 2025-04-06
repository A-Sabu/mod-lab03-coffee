// Copyright 2025 A-Sabu
#include "Automata.h"
#include <iostream>
#include <vector>
#include <string>

int main(int argc, char** argv) {

        vector<string> menu = { "Capuchino", "Expresso", "Raf" };
        vector<float> prices = { 1.5, 2.5, 5.5 };

        Automata coffeeMachine(menu, prices);

        coffeeMachine.on();
        coffeeMachine.coin(6);
        coffeeMachine.choice(2);
        coffeeMachine.check();

        return 1;
}
