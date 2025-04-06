// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"
#include <vector>
#include <string>

TEST(task_state, test1) {
    vector<string> menu = { "Capuchino", "Expresso", "Raf" };
    vector<float> prices = { 1.5, 2.5, 5.5 };

    Automata coffeeMachine(menu, prices);

    coffeeMachine.on();

    string result = coffeeMachine.getState();
    EXPECT_EQ("WAIT", result);
}

TEST(task_state, test2) {
    vector<string> menu = { "Capuchino", "Expresso", "Raf" };
    vector<float> prices = { 1.5, 2.5, 5.5 };

    Automata coffeeMachine(menu, prices);

    coffeeMachine.on();
    coffeeMachine.coin(3);

    string result = coffeeMachine.getState();
    EXPECT_EQ("ACCEPT", result);
}

TEST(task_state, test3) {
    vector<string> menu = { "Capuchino", "Expresso", "Raf" };
    vector<float> prices = { 1.5, 2.5, 5.5 };

    Automata coffeeMachine(menu, prices);

    coffeeMachine.on();
    coffeeMachine.coin(3);
    coffeeMachine.choice(1);

    string result = coffeeMachine.getState();
    EXPECT_EQ("CHECK", result);
}

TEST(task_state, test4) {
    vector<string> menu = { "Capuchino", "Expresso", "Raf" };
    vector<float> prices = { 1.5, 2.5, 5.5 };

    Automata coffeeMachine(menu, prices);

    coffeeMachine.on();
    coffeeMachine.coin(3);
    coffeeMachine.choice(1);
    coffeeMachine.check();

    string result = coffeeMachine.getState();
    EXPECT_EQ("WAIT", result);
}

TEST(task_state, test5) {
    vector<string> menu = { "Capuchino", "Expresso", "Raf" };
    vector<float> prices = { 1.5, 2.5, 5.5 };

    Automata coffeeMachine(menu, prices);

    coffeeMachine.on();
    coffeeMachine.coin(3);
    coffeeMachine.choice(1);
    coffeeMachine.check();
    coffeeMachine.off();

    string result = coffeeMachine.getState();
    EXPECT_EQ("OFF", result);
}

TEST(task_state, test6) {
    vector<string> menu = { "Capuchino", "Expresso", "Raf" };
    vector<float> prices = { 1.5, 2.5, 5.5 };

    Automata coffeeMachine(menu, prices);

    coffeeMachine.on();
    coffeeMachine.on();

    string result = coffeeMachine.getState();
    EXPECT_EQ("WAIT", result);
}

TEST(task_state, test7) {
    vector<string> menu = { "Capuchino", "Expresso", "Raf" };
    vector<float> prices = { 1.5, 2.5, 5.5 };

    Automata coffeeMachine(menu, prices);

    coffeeMachine.on();
    coffeeMachine.coin(1);
    coffeeMachine.cancel();

    string result = coffeeMachine.getState();
    EXPECT_EQ("WAIT", result);
}

TEST(task_state, test8) {
    vector<string> menu = { "Capuchino", "Expresso", "Raf" };
    vector<float> prices = { 1.5, 2.5, 5.5 };

    Automata coffeeMachine(menu, prices);

    coffeeMachine.on();
    coffeeMachine.coin(1);
    coffeeMachine.choice(0);
    coffeeMachine.cancel();

    string result = coffeeMachine.getState();
    EXPECT_EQ("WAIT", result);
}

TEST(task_state, test9) {
    vector<string> menu = { "Capuchino", "Expresso", "Raf" };
    vector<float> prices = { 1.5, 2.5, 5.5 };

    Automata coffeeMachine(menu, prices);

    coffeeMachine.on();
    coffeeMachine.coin(1);
    coffeeMachine.coin(2);

    string result = coffeeMachine.getState();
    EXPECT_EQ("ACCEPT", result);
}

TEST(task_state, test10) {
    vector<string> menu = { "Capuchino", "Expresso", "Raf" };
    vector<float> prices = { 1.5, 2.5, 5.5 };

    Automata coffeeMachine(menu, prices);

    coffeeMachine.on();
    coffeeMachine.coin(2);
    coffeeMachine.choice(2);
    coffeeMachine.check();

    string result = coffeeMachine.getState();
    EXPECT_EQ("WAIT", result);
}

TEST(task_state, test11) {
    vector<string> menu = { "Capuchino", "Expresso", "Raf" };
    vector<float> prices = { 1.5, 2.5, 5.5 };

    Automata coffeeMachine(menu, prices);

    coffeeMachine.on();
    coffeeMachine.coin(2);
    coffeeMachine.check();

    string result = coffeeMachine.getState();
    EXPECT_EQ("ACCEPT", result);
}

TEST(task_cash, test1) {
    vector<string> menu = { "Capuchino", "Expresso", "Raf" };
    vector<float> prices = { 1.5, 2.5, 5.5 };

    Automata coffeeMachine(menu, prices);

    coffeeMachine.on();
    coffeeMachine.coin(2);
    coffeeMachine.coin(2);

    float result = coffeeMachine.giveChange();
    EXPECT_EQ(4.0, result);
}
