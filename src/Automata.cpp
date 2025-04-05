#include "Automata.h"

Automata::Automata(float cash, vector<string> menu, vector<float> prices) :
	_cash(cash), _menu(menu), _prices(prices), _state(OFF) {}

inline void Automata::on() {};
inline void Automata::off() {};
inline void Automata::coin() {};
inline void Automata::etMenu() {};
inline void Automata::getState() {};
inline void Automata::choice() {};
inline void Automata::check() {};
inline void Automata::cancel() {};
inline void Automata::cook() {};
inline void Automata::finish() {};