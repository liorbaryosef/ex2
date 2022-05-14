#include <iostream>
#include "Card.h"
#include "utilities.h"
#include "Mtmchkin.h"

int main() {
    //CardStats stats(3, 40, 10, 30, 1, 20);
    Card battle(CardType::Battle, CardStats(3, 40, 10, 30, 1, 20));
    battle.Card::printInfo();
    /*Player player1("John", 150, 2);
    Player player2("Sam", 300);
    player2.Player::printInfo();
    battle.applyEncounter(player2);
    player2.Player::printInfo();
    CardStats stats2(4, 5, 6, 7, 8, 9);
    Card buff(CardType::Buff, stats2);
    buff.Card::printInfo();
    std::cout << "Applying buff to John" << std::endl;
    buff.applyEncounter(player1);
    player1.Player::printInfo();
    std::cout << "Applying buff to Sam" << std::endl;
    buff.applyEncounter(player2);
    player2.Player::printInfo();
    std::cout << "Applying battle to John" << std::endl;
    battle.applyEncounter(player1);
    player1.Player::printInfo();
    buff.applyEncounter(player2);
    player2.Player::printInfo();
    CardStats statsStrong(400, 40, 34, 2, 3, 50);
    Card strongBattle(CardType::Battle, statsStrong);
    strongBattle.Card::applyEncounter(player1);
    player1.Player::printInfo();
    CardStats stats3(1, 2, 3, 4, 5, 6);
    Card heal(CardType::Heal, stats3);
    heal.Card::printInfo();
    heal.applyEncounter(player1);
    player1.Player::printInfo();
    Card cards[1];
    cards[0] = Card(CardType::Treasure, stats);
    Mtmchkin game("Daniel", cards, 1);
    game.printInfo();
    Player player3 = player1;
    player3.printInfo();
    Mtmchkin gameCopy("New", cards, 2);
    gameCopy = game;
    std::cout << "Printing After Implementation\n";
    gameCopy.printInfo();
    Mtmchkin gameCopy2(game);
    std::cout << "Printing After Copy\n";
    gameCopy.printInfo();*/

    int numOfCards = 4;

    return 0;
}