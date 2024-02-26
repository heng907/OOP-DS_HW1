#include "GameCharacter.h"

GameCharacter::GameCharacter() :
     Object("","GameCharacter"),maxHealth(0),currentHealth(0),attack(0),defense(0){}

GameCharacter::GameCharacter(string name ,string tag , int health , int attack , int defense) : Object(name, tag) {
        this -> maxHealth = health ;
        this -> currentHealth = health ;
        this -> attack = attack ;
        this -> defense = defense ;
}

bool GameCharacter::checkIsDead ( ) {
        return this -> currentHealth <= 0;
}

int GameCharacter::takeDamage (int dmg) {
        return this -> currentHealth -= dmg ;
}


//set and get functions
void GameCharacter::setMaxHealth (int health){
        this -> maxHealth = health ;
}

void GameCharacter::setCurrentHealth (int health) {
        this -> currentHealth = health ;
}

void GameCharacter::setAttack (int attack) {
        this -> attack = attack ;
}

void GameCharacter::setDefense (int defense) {
        this -> defense = defense ;
}

int GameCharacter::getMaxHealth ( ) {
        return this -> maxHealth ;
}

int GameCharacter::getCurrentHealth ( ) {
        return this -> currentHealth ;
}

int GameCharacter::getAttack ( ) {
        return this -> attack ;
}

int GameCharacter::getDefense ( ) {
        return this -> defense ;
}
