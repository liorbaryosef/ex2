#include <iostream>
#include "Card.h"
#include "utilities.h"
#include "Player.h"

Card::Card(CardType type, const CardStats& stats) {
    m_effect = type;
    m_stats = stats;
}

void Card::applyEncounter(Player& player) const { //check if player is not null???
    if (m_effect == CardType::Battle) {
        bool win = (player.getAttackStrength() >= m_stats.force);
        printBattleResult(win);
        if (win) {
            player.levelUp();
            player.addCoins(m_stats.loot);
        }
        else {
            player.damage(m_stats.hpLossOnDefeat);
        }
    }
    else if (m_effect == CardType::Treasure) {
        player.addCoins(m_stats.loot);
    }
    else {
        if (player.pay(m_stats.cost)) {
            if (m_effect == CardType::Heal) {
                player.heal(m_stats.heal);
            }
            else{
                player.buff(m_stats.buff);
            }
        }
    }
}

void Card::printInfo() const {
    switch (m_effect) {
        case CardType::Battle: 
            printBattleCardInfo(m_stats);
            break;
        case CardType::Buff:
            printBuffCardInfo(m_stats);
            break;
        case CardType::Heal:
            printHealCardInfo(m_stats);
            break;
        case CardType::Treasure:
            printTreasureCardInfo(m_stats);
            break;
    }
}