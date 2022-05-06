#include "Card.h"
#include "Mtmchkin.h"
#include <iostream>
#include <string>

Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards) {
    m_player = playerName; //don't need malloc here because of the string library. Need to free though?
    m_numOfCards = numOfCards;
    m_cards = new Card[m_numOfCards]; //remember to free!!!
}

