#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "GameCharacter.h"
#include "Player.h"

using namespace std;

class Monster: public GameCharacter
{
private:
    //other private function
    bool isBoss ;

public:
    Monster();
    Monster(string,int,int,int);

    /* Virtual function that you need to complete   */
    /* In Monster, this function should deal with   */
    /* the combat system.                           */
    bool triggerEvent(Object*);

    //set&get function
    void setIsBoss( int ) ;
    bool getIsBoss( ) ;
    void printStatus ( ) ;
};


#endif // ENEMY_H_INCLUDED
