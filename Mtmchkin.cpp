#include "Mtmchkin.h"
#include <string>
#include <iostream>
#include "Card.h"
#include "utilities.h"
#include "Player.h"

//Do we need some sort of default values for a game with no given parameters?
Mtmchkin::Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards) :  m_player(playerName)
{ //check input??
    m_numOfCards = numOfCards;
    m_cards = new Card[m_numOfCards]; //remember to free!!
    for (int i = 0; i < m_numOfCards; i++) {
        m_cards[i] = cardsArray[i];
    }
    m_status = GameStatus::MidGame;
    m_nextCard = 0;
}

//Implementation Constructor
Mtmchkin& Mtmchkin::operator=(const Mtmchkin& original)
{
    if (this == &original) {
        return *this;
    }
    delete[] m_cards;
    m_numOfCards = original.m_numOfCards;
    m_cards = new Card[original.m_numOfCards]; //remember to free!!
    for (int i = 0; i < m_numOfCards; i++) {
        m_cards[i] = original.m_cards[i];
    }
    m_status = original.m_status;
    m_nextCard = original.m_nextCard;
    m_player = original.m_player;
    return *this;
}

//Copy constructor
Mtmchkin::Mtmchkin(const Mtmchkin& original) : 
    m_player(original.m_player),
    m_cards(new Card[original.m_numOfCards]),
    m_numOfCards(original.m_numOfCards),
    m_status(original.m_status),
    m_nextCard(original.m_nextCard)
{
    for (int i = 0; i < m_numOfCards; i++) {
        m_cards[i] = original.m_cards[i];
    }
}

//Destructor
Mtmchkin::~Mtmchkin()
{
    delete[] m_cards;
}

//Return the game status
GameStatus Mtmchkin::getGameStatus() const
{
    return m_status;
}

//Play the next card in the deck, change the game status accordingly
void Mtmchkin::playNextCard()
{
    m_cards[m_nextCard].printInfo();
    m_cards[m_nextCard].applyEncounter(m_player);
    m_player.printInfo();
    if (m_nextCard == m_numOfCards - 1) {
        m_nextCard = 0;
    }
    else {
        m_nextCard++;
    }
    if (m_player.getLevel() == MAX_LEVEL) {
        m_status = GameStatus::Win;
    }
    else if (m_player.isKnockedOut()) {
        m_status = GameStatus::Loss;
    }
}

//Check if the game is over, return boolean value accordingly
bool Mtmchkin::isOver()
{
    if (m_status == GameStatus::MidGame) {
        return false;
    }
    else {
        return true;
    }
}

//HELPER FUNCTION TEMPORARILY CREATED
void Mtmchkin::printInfo()
{
    std::cout << "Printing Game Info:\n";
    m_player.printInfo();
    m_cards[0].printInfo();
}

