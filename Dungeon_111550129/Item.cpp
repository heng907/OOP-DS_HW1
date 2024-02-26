#include "Item.h"

Item::Item() : Object ( "" , "Item") , health(0) , attack(0) , defense(0){}

Item::Item (string name,string type, int health , int attack , int defense) : Object (name , "Item"),type(type),health(health),attack(attack),defense(defense){
}

//virtual function

bool Item::triggerEvent(Object* object){
        Player* player = dynamic_cast<Player*>(object) ;
        cout << "You got "<<getName( ) <<endl ;
        player -> addItem(*this) ;
        return true ;
}


//set & get functions

    int Item::getHealth ( ) {
            return this -> health ;
    }

    int Item::getAttack ( ) {
            return this -> attack ;
    }

    int Item::getDefense( ) {
            return this -> defense;
    }

    string Item::getType(){
            return type;
    }

    void Item::setHealth (int health){
            this -> health = health ;
    }

    void Item::setAttack (int attack){
            this ->attack = attack ;
    }

     void Item::setDefense (int defense) {
            this -> defense = defense ;
     }

     void Item::setType(string typ){
            this ->type = typ;
     }
