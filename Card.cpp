#include <iostream>
#include "Card.h"
#include "utilities.h"
#include <string> //do i actually need this

Card::Card(CardType type, const CardStats& stats) {
    this->m_effect = type;
    this->m_stats = stats;
}

void applyEncounter(Player& player) {
    if (this->m_effect == Battle) {
        bool win = (player.force >= this->m_stats.force);
        printBattleResult(win);
        if (win) {
            player.levelUp();
            player.addCoins(this->m_stats.loot);
        }
        else {
            player.damage(this->m_stats.hpLossOnDefeat); //check that not negative in function or here?
        }
    }
    else if (this->m_effect == Treasure) { //should this just be if?
        player.addCoins(this->m_stats.loot); //check that should be loot and not something else
    }
    else {
        if (player.pay(this->m_stats.cost)) {
            if (this->m_effect == Heal) {
                player.heal(this->m_stats.heal);
            }
            else{
                player.buff(this->m_stats.buff);
            }
        }
    }
}

void printInfo() {
    switch (this->m_effect) {
        case Battle: 
            printBattleCardInfo(this);
            break;
        case Buff:
            printBuffCardInfo(this);
            break;
        case Heal:
            printHealCardInfo(this);
            break;
        case Treasure:
            printTreasureCardInfo(this);
            break;
    }
}