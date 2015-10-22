#include "Turn.hpp"

void turn::Turn::switch_turn() {
    if (Turn::player == turn::CurrentTurn::DRAGON)
        Turn::player = turn::CurrentTurn::ELF;
    else
        Turn::player = turn::CurrentTurn::DRAGON;
}
