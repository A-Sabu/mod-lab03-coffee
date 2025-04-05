// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"

TEST(task1, test1) {
    vector<string> menu = { "Capuchino", "Expresso", "Raf" };
    vector<float> prices = { 1.5, 2.5, 5.5 };

    Automata coffeeMachine(menu, prices);
    
    coffeeMachine.on();
    
    string result = coffeeMachine.getState();
    EXPECT_EQ("WAIT", result);
  }
