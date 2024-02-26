#include "Monster.h"

#define NC "\e[0m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define CYN "\e[0;36m"
#define REDB "\e[41m"

Monster::Monster ( ) : GameCharacter ("", "Monster", 0 ,0 ,0 ) , isBoss (false) {
}

Monster::Monster ( string name ,int health , int attack , int defense) : GameCharacter(name, "Monster" , health , attack , defense) ,isBoss(false) {
}

//virtual functions
int calculateDamage (int attack , int defense) {
        return attack * attack / (attack + defense) ;
}

void Monster::setIsBoss (int _isBoss) {
        isBoss = _isBoss ;
}

bool Monster::getIsBoss ( ) {
        return isBoss ;
}

void Monster::printStatus ( ) {
        cout << "Monster : " << getName( ) << endl ;
        cout << "HP : " << getMaxHealth ( ) << endl ;
        cout << "ATK : " << getAttack ( ) << endl ;
        cout << "DEF : " << getDefense ( ) << endl ;
}

//triggerEvent
bool Monster::triggerEvent(Object* object){
        Player* player = dynamic_cast<Player*>(object);
        player -> triggerEvent(player);
        cout << " Player " << player -> getName() << ", you  encounter a monster ! " <<endl;
        printStatus();
        char choice='Z';
        int player_dmg = calculateDamage(player->getAttack(),getDefense());
        int monster_dmg = calculateDamage(getAttack(),player->getDefense());
        do {
                if(choice == 'S' || choice == 's'){
                    player->triggerEvent(player);
                }
                else if (choice =='R' || choice == 'r'){
                    Room*tmp = player->getCurrentRoom();
                    player->setCurrentRoom(player->getPreviousRoom());
                    player->setPreviousRoom(tmp);
                    return true;
                }
                else if(choice == 'A' || choice == 'a'){
                    cout << " Player " << player->getName() << " deal " << player_dmg << " damages to Monster " << getName() << endl;
                    setCurrentHealth(getCurrentHealth()-player_dmg);
                    if(getCurrentHealth() <= 0){
                        cout << "Monster " << getName() << " has been killed." << endl;
                        player->getCurrentRoom()->popObject(this);
                        return true;
                    }
                    cout << "Monster " << getName() << "deal " << monster_dmg << " damages to player " << player->getName() << endl ;
                    player->setCurrentHealth(player->getCurrentHealth() - monster_dmg);
                    if(player->getCurrentHealth()<=0){
                        cout << " player " << player->getName() << " is dead . " << endl ;
                        return false;
                    }
                }
                else {
                    cout << "Invalid input. " << endl ;
                }
                cout << "(R)etreat" << endl;
                cout << "(A)ttack" << endl;
                cout << "(S)tatus" << endl;
                cout << "which do you want to do ? " ;
        }while(cin >> choice);

}









