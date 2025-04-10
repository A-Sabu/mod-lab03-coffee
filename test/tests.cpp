// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"
#include <vector>
#include <string>

std::vector<std::string> menu = { "Capuchino", "Expresso", "Raf" };
std::vector<float> prices = { 1.5, 2.5, 5.5 };

TEST(task_state, test1) {
    Automata coffeeMachine(menu, prices);

    coffeeMachine.on();

    std::string result = coffeeMachine.getState();
    EXPECT_EQ("WAIT", result);
}

TEST(task_state, test2) {
    Automata coffeeMachine(menu, prices);

    coffeeMachine.on();
    coffeeMachine.coin(3);

    std::string result = coffeeMachine.getState();
    EXPECT_EQ("ACCEPT", result);
}

TEST(task_state, test3) {
    Automata coffeeMachine(menu, prices);

    coffeeMachine.on();
    coffeeMachine.coin(3);
    coffeeMachine.choice(1);

    std::string result = coffeeMachine.getState();
    EXPECT_EQ("CHECK", result);
}

TEST(task_state, test4) {
    Automata coffeeMachine(menu, prices);

    coffeeMachine.on();
    coffeeMachine.coin(3);
    coffeeMachine.choice(1);
    coffeeMachine.check();

    std::string result = coffeeMachine.getState();
    EXPECT_EQ("WAIT", result);
}

TEST(task_state, test5) {
    Automata coffeeMachine(menu, prices);

    coffeeMachine.on();
    coffeeMachine.coin(3);
    coffeeMachine.choice(1);
    coffeeMachine.check();
    coffeeMachine.off();

    std::string result = coffeeMachine.getState();
    EXPECT_EQ("OFF", result);
}

TEST(task_state, test6) {
    Automata coffeeMachine(menu, prices);

    coffeeMachine.on();
    coffeeMachine.on();

    std::string result = coffeeMachine.getState();
    EXPECT_EQ("WAIT", result);
}

TEST(task_state, test7) {
    Automata coffeeMachine(menu, prices);

    coffeeMachine.on();
    coffeeMachine.coin(1);
    coffeeMachine.cancel();

    std::string result = coffeeMachine.getState();
    EXPECT_EQ("WAIT", result);
}

TEST(task_state, test8) {
    Automata coffeeMachine(menu, prices);

    coffeeMachine.on();
    coffeeMachine.coin(1);
    coffeeMachine.choice(0);
    coffeeMachine.cancel();

    std::string result = coffeeMachine.getState();
    EXPECT_EQ("WAIT", result);
}

TEST(task_state, test9) {
    Automata coffeeMachine(menu, prices);

    coffeeMachine.on();
    coffeeMachine.coin(1);
    coffeeMachine.coin(2);

    std::string result = coffeeMachine.getState();
    EXPECT_EQ("ACCEPT", result);
}

TEST(task_state, test10) {
    Automata coffeeMachine(menu, prices);

    coffeeMachine.on();
    coffeeMachine.coin(2);
    coffeeMachine.choice(2);
    coffeeMachine.check();

    std::string result = coffeeMachine.getState();
    EXPECT_EQ("WAIT", result);
}

TEST(task_state, test11) {
    Automata coffeeMachine(menu, prices);

    coffeeMachine.on();
    coffeeMachine.coin(2);
    coffeeMachine.check();

    std::string result = coffeeMachine.getState();
    EXPECT_EQ("ACCEPT", result);
}

TEST(task_cash, test1) {
    Automata coffeeMachine(menu, prices);

    coffeeMachine.on();
    coffeeMachine.coin(2);
    coffeeMachine.coin(2);

    float result = coffeeMachine.giveChange();
    EXPECT_EQ(4.0, result);
}
