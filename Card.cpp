#include <iostream>
#include "Card.h"
#include "utilities.h"
#include <string> //do i actually need this
#include "Player.h"

Card::Card(CardType type, const CardStats& stats) {
    this->m_effect = type;
    this->m_stats = stats;
}

void Card::applyEncounter(Player& player) const {
    if (this->m_effect == CardType::Battle) {
        bool win = (player.Player::getAttackStrength() >= this->m_stats.force);
        printBattleResult(win);
        if (win) {
            player.levelUp();
            player.addCoins(this->m_stats.loot);
        }
        else {
            player.damage(this->m_stats.hpLossOnDefeat); //check that not negative in function or here?
        }
    }
    else if (this->m_effect == CardType::Treasure) {
        player.addCoins(this->m_stats.loot);
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
            printBattleCardInfo(this->m_stats);
            break;
        case CardType::Buff:
            printBuffCardInfo(this->m_stats);
            break;
        case CardType::Heal:
            printHealCardInfo(this->m_stats);
            break;
        case CardType::Treasure:
            printTreasureCardInfo(this->m_stats);
            break;
    }
}