#include "Player.h"
#include "utilities.h"
#include <iostream>
#include <string>
using std::cout;
using std::endl;


//--------------------------------Helper Functions--------------------------------
int validateHP(int givenMaxHP);
int validateForce(int givenForce);
//--------------------------------------------------------------------------------


//Constructor for player
Player::Player(const char* givenName, int givenMaxHP /*DEFAULT_MAX_HP*/, int givenForce /*DEFAULT_FORCE*/)
{
    m_name = givenName;
    m_level = 1;
    m_force = validateForce(givenForce);
    m_hp = validateHP(givenMaxHP);
    m_coins = 0;
    m_maxHP = validateHP(givenMaxHP);
}

//Prints to screen the player's current stats
void Player::printInfo() const
{
    printPlayerInfo(m_name.c_str(), m_level, m_force, m_hp, m_coins);
}

//Increases the player's level, until maximum level (10) is reached
void Player::levelUp()
{
    if (m_level < MAX_LEVEL) {
        m_level++;
    }
}

//Returns the player's current level
int Player::getLevel() const
{
    return m_level;
}

//Increases player's force by requested amount
void Player::buff(const int increaseForce)
{
    if (increaseForce >= 0) {
        m_force += increaseForce;
    }
}

//Increases player's Health Points by requested amount, until maximum is reached
void Player::heal(const int increaseHP)
{
    if (increaseHP >= 0) {
        if ((m_hp + increaseHP) > m_maxHP) {
            m_hp = m_maxHP;
        }
        else {
            m_hp += increaseHP;
        }
    }
}

//Decreases player's Health Points by requested amount, until the value is 0
void Player::damage(const int decreaseHP)
{
    if (decreaseHP >= 0) {
        if ((m_hp - decreaseHP) < 0) {
            m_hp = 0;
        }
        else {
            m_hp -= decreaseHP;
        }
    }
}

//Checks if the player's Health Points has reached 0
//Return true if it has, otherwise return false
bool Player::isKnockedOut() const
{
    if (m_hp == 0) {
        return true;
    }
    return false;
}

//Increases the player's coins by the requested amount
void Player::addCoins(const int increaseCoins)
{
    if (increaseCoins >= 0) {
        m_coins += increaseCoins;
    }
}

//Decreases the player's coins by the requested amount.
//Return true if the payment was completed successfully, otherwise return false.
bool Player::pay(const int decreaseCoins)
{
    if (decreaseCoins <= 0) {
        return true;
    }
    if (m_coins - decreaseCoins >= 0) {
        m_coins -= decreaseCoins;
        return true;
    }
    return false;
}

//Returns the players attack strength: the player's level + the player's force
int Player::getAttackStrength() const
{
    return (m_level + m_force);
}


//--------------------------------Helper Functions--------------------------------

//Validates the given maximum Health Point value from input
int validateHP(int givenMaxHP)
{
    if (givenMaxHP <= 0) {
        return Player::DEFAULT_MAX_HP;
    }
    return givenMaxHP;
}


//Validates the force from input
int validateForce(int givenForce)
{
    if (givenForce <= 0) {
        return Player::DEFAULT_FORCE;
    }
    return givenForce;
}
