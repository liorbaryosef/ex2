#include <iostream>
#include "Card.h"
#include "utilities.h"

int main() {
    CardStats stats(3, 40, 10, 30, 1, 20);
    Card card(CardType::Battle, stats);
    card.Card::printInfo();
    Player player1("John", 150, 2);
    Player player2("Sam", 300);
    player2.Player::printInfo();
    card.applyEncounter(player2);
    player2.Player::printInfo();
    CardStats stats2(4, 5, 6, 7, 8, 9);
    Card card2(CardType::Buff, stats2);
    card2.Card::printInfo();
    player1.Player::printInfo();
    card2.applyEncounter(player2);
    player2.Player::printInfo();
    return 0;
}