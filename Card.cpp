#include <iostream>
#include "Card.h"
#include "utilities.h"
#include <string> //do i actually need this

Card::Card(CardType type, const CardStats& stats) {
    this->m_effect = type;
    this->m_stats = stats;
}

void Card::applyEncounter(Player& player) const {
    if (this->m_effect == CardType::Battle) {
        bool win = (player.force >= this->m_stats.force); //how do you access fields outside of your class?
        printBattleResult(win);
        if (win) {
            player.levelUp();
            player.addCoins(this->m_stats.loot);
        }
        else {
            player.damage(this->m_stats.hpLossOnDefeat); //check that not negative in function or here?
        }
    }
    else if (this->m_effect == CardType::Treasure) { //should this just be if?
        player.addCoins(this->m_stats.loot); //check that should be loot and not something else
    }
    else {
        if (player.pay(this->m_stats.cost)) {
            if (this->m_effect == CardType::Heal) {
                player.heal(this->m_stats.heal);
            }
            else{
                player.buff(this->m_stats.buff);
            }
        }
    }
}

void Card::printInfo() const {
    switch (this->m_effect) {
        case CardType::Battle: 
            printBattleCardInfo(this);
            break;
        case CardType::Buff:
            printBuffCardInfo(this);
            break;
        case CardType::Heal:
            printHealCardInfo(this);
            break;
        case CardType::Treasure:
            printTreasureCardInfo(this);
            break;
    }
}