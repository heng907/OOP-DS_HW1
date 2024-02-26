#include "Player.h"

Player::Player ( ) {

}

Player::Player(string name ,int hp ,int atk,int def) :
        GameCharacter(name, "Player" , hp, atk,def) {

        }

void Player::addItem(Item new_item){
        inventory.push_back(new_item) ;
}

void Player::increaseStates(int hp, int atk ,int def){
        setCurrentHealth(min(getCurrentHealth( ) + hp, getMaxHealth( ))) ;
        setAttack(getAttack( ) + atk ) ;
        setDefense(getDefense( ) + def) ;
}

void Player::changeRoom(Room* new_room){
        previousRoom = currentRoom;
        currentRoom = new_room;
}

//triggerEvent function
bool Player:: triggerEvent(Object* ){
        cout << "-----------------S T A T U S-----------------" << endl ;
        cout << getName() << endl;
        cout << "HP :  " << getCurrentHealth() << "/" << getMaxHealth() << endl ;
        cout << "ATK :  " << getAttack() <<endl;
        cout << "DEF :  " << getDefense() << endl ;
        auto inve = getInventory();
        if(inve.size()!=0){
            cout << "Item: ";
            for(auto i: inve){
                cout << i.getName() << ", " ;
            }
            cout << endl;
        }
        cout << "Equipment: " << endl;
        cout << "> weapon     : " << (weapon == nullptr ? "(empty)" : weapon->getName()) << endl;
        cout << "-----------------------------------------------" << endl;
        return true ;
}

void Player::setCurrentRoom (Room* room) {
        currentRoom = room ;
}

void Player::setPreviousRoom (Room* room) {
        previousRoom = room ;
}

void Player::setInventory (vector<Item> invent) {
        inventory = invent ;
}

Room* Player::getCurrentRoom( ) {
        return currentRoom ;
}

Room* Player::getPreviousRoom( ) {
        return previousRoom ;
}

vector<Item> Player::getInventory( ) {
        return inventory ;
}

Item* Player::getWeapon( ) {
        return weapon ;
}

//
void Player::setWeapon(Item* newWeapon){
    increaseStates(newWeapon->getHealth(), newWeapon->getAttack(), newWeapon->getDefense());
    for(auto it=inventory.begin();it!=inventory.end();it++){
        if(it->getName() == newWeapon->getName()){
            inventory.erase(it);
            break;
        }
    }
    if(weapon != nullptr){
        increaseStates(-weapon->getHealth(), -weapon->getAttack(), -weapon->getDefense());
        inventory.push_back(*weapon);
    }
    weapon = newWeapon;
}

void Player::equip(){
    while(true){
        cout << "Equipment: " << endl;
        cout << "> Weapon     : " << (weapon == nullptr ? "(empty)" : (weapon->getName() + " ATK: " + to_string(weapon->getAttack()) + " DEF: " + to_string(weapon->getDefense()))) << endl;
        char c;
        do{
            cout << "(W)eapon" << endl;
            cout << "(E)xit" << endl;
            cout << "Do you want to equip? ";
        } while(cin >> c && (c != 'w' && c != 'W' && c != 'e' && c != 'E'));

        if(c == 'e' || c == 'E') return;

        if(c == 'w' || c == 'W'){
            cout << "> Weapon     : " << (weapon == nullptr ? "(empty)" : (weapon->getName() + " ATK: " + to_string(weapon->getAttack()) + " DEF: " + to_string(weapon->getDefense()))) << endl;
            cout << "Invetory: " << endl;
            int idx = 0;
            vector<Item> rep;
            for(Item i: inventory){
                if(i.getType() == "weapon"){
                    cout << "> " << idx ++ << ": "<< i.getName() + " ATK: " + to_string(i.getAttack()) + " DEF: " + to_string(i.getDefense()) << endl;
                    rep.push_back(i);
                }
            }
            idx =-1;
            do{
                if(idx >= 0 && idx < (int)rep.size()){
                    Item* newed = new Item(rep[idx]);
                    setWeapon(newed);
                    break;
                }
                cout << "Which equipment does you want to put on (Enter -1 to leave) > ";
            } while(cin >> idx && idx != -1);
        }
    }
}
