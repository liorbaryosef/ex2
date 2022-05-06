//
// Created by liorb on 06/05/2022.
//

#include "Player.h"
#include "utilities.h"
#include <iostream>
#include <string>
using std::cout;
using std::endl;

int main()
{
    //Creating Players----------------------------------------------------
    Player player1("Voldemort", 150, 2);
    Player player2("Neville Longbottom", 300, -5);
    Player player3("Dumbledore", -300, 3);
    Player player4("Harry", 300);
    Player player5("Hermione", -9);
    Player player6("Ron");
    Player player7("Ginny", 0, 500);
    Player player8("Fluffy&^*Fluffy", 100, 5);
    Player player9("Hagrid", -100, -5);
    Player player10 = player1;

    //Printing Players----------------------------------------------------
    player1.printInfo();
    player2.printInfo();
    player3.printInfo();
    player4.printInfo();
    player5.printInfo();
    player6.printInfo();
    player7.printInfo();
    player8.printInfo();
    player9.printInfo();
    player10.printInfo();

    //Testing Level-------------------------------------------------------
    cout << "********Adding Levels to Harry" << endl;
    player4.levelUp();
    player4.levelUp();
    player4.levelUp();
    player4.levelUp();
    player4.levelUp();
    player4.levelUp();
    player4.levelUp();
    player4.levelUp();
    player4.levelUp();
    int tmpLevel = player4.getLevel();
    cout << "----Current Level: " << tmpLevel << endl;
    player4.levelUp();
    tmpLevel = player4.getLevel();
    cout << "----Tried to add one more level to Harry: " << tmpLevel << endl;
    player4.printInfo();
    player10.levelUp();

    //Testing Buff--------------------------------------------------------
    cout << "********Buffing Voldemort's force:" << endl;
    cout << "----Before:" << endl;
    player1.printInfo();
    player1.buff(1000);
    cout << "----After +1000:" << endl;
    player1.printInfo();
    player1.buff(-8000);
    cout << "----After -8000:" << endl;
    player1.printInfo();

    //Testing Damage & Knockout-------------------------------------------
    cout << "********Damaging Voldemort:" << endl;
    cout << "----Before:" << endl;
    player1.printInfo();
    player1.damage(100);
    cout << "----After +100:" << endl;
    player1.printInfo();
    if (player1.isKnockedOut()){
        std::cout << "----Voldemort is knocked out" << endl;
    }
    player1.damage(-8000);
    cout << "----After -8000:" << endl;
    player1.printInfo();
    player1.damage(100);
    cout << "----After +100:" << endl;
    player1.printInfo();
    if (player1.isKnockedOut()){
        std::cout << "----Voldemort is knocked out" << endl;
    }

    //Testing Heal--------------------------------------------------------
    cout << "********Healing Ginny:" << endl;
    cout << "----Before:" << endl;
    player7.printInfo();
    player7.heal(10);
    cout << "----After +10:" << endl;
    player7.printInfo();
    player7.heal(-10);
    cout << "----After -10:" << endl;
    player7.printInfo();
    cout << "********Healing Ron:" << endl;
    cout << "----Before:" << endl;
    player6.printInfo();
    player6.damage(100);
    player6.heal(5);
    cout << "----After +5:" << endl;
    player6.printInfo();
    player6.heal(5000);
    cout << "----After +5000:" << endl;
    player6.printInfo();
    player6.heal(-150);
    cout << "----After -150:" << endl;
    player6.printInfo();

    //Testing addCoins & Pay----------------------------------------------
    cout << "********Adding/Paying Hagrid:" << endl;
    cout << "----Before:" << endl;
    player9.printInfo();
    player9.addCoins(350);
    cout << "----After adding +350:" << endl;
    player9.printInfo();
    player9.addCoins(-350);
    cout << "----After adding -350:" << endl;
    player9.printInfo();
    if (!player9.pay(350)){
        std::cout << "Not enough coins" << endl;
    }
    cout << "----After paying +350:" << endl;
    player9.printInfo();
    if (!player9.pay(-350)){
        std::cout << "Not enough coins" << endl;
    }
    cout << "----After paying -350:" << endl;
    player9.printInfo();
    player9.addCoins(50);
    cout << "----After adding +50:" << endl;
    player9.printInfo();
    if (!player9.pay(350)){
        std::cout << "Not enough coins" << endl;
    }
    cout << "----After paying +350:" << endl;
    player9.printInfo();


    //Testing Attack Strength---------------------------------------------
    int as = 0;
    player1.printInfo();
    as = player1.getAttackStrength();
    cout << "----AttackStrength: " << as << endl;
    player2.printInfo();
    as = player2.getAttackStrength();
    cout << "----AttackStrength: " << as << endl;
    player3.printInfo();
    as = player3.getAttackStrength();
    cout << "----AttackStrength: " << as << endl;
    player4.printInfo();
    as = player4.getAttackStrength();
    cout << "----AttackStrength: " << as << endl;
    player5.printInfo();
    as = player5.getAttackStrength();
    cout << "----AttackStrength: " << as << endl;
    player6.printInfo();
    as = player6.getAttackStrength();
    cout << "----AttackStrength: " << as << endl;
    player7.printInfo();
    as = player7.getAttackStrength();
    cout << "----AttackStrength: " << as << endl;
    player8.printInfo();
    as = player8.getAttackStrength();
    cout << "----AttackStrength: " << as << endl;
    player9.printInfo();
    as = player9.getAttackStrength();
    cout << "----AttackStrength: " << as << endl;
    player10.printInfo();
    as = player10.getAttackStrength();
    cout << "----AttackStrength: " << as << endl;

    return 0;
}