#include "NPC.h"


NPC::NPC ( ) {

}

NPC::NPC (string name, string script, vector<Item>com) :
    GameCharacter(name, "NPC" , 0 ,0 ,0), script(script), commodity (com) {

    }

void NPC::listCommodity ( ) {
            int index = 0 ;
            for (auto i : this -> commodity) {
                cout << index++<< ": "<<i.getType()<< " " <<i.getName( ) << "HP: "<<i.getHealth( )<< ",ATK: " <<i.getAttack( ) << ",DEF: " << i.getDefense( ) << endl ;
            }
    }

    //virtual function

    bool NPC::triggerEvent(Object* object) {
            Player* player = dynamic_cast <Player*>(object) ;
            cout << getScript( ) << endl ;

            int idx = -1;
            do{
                if(0 <= idx && idx < (int)commodity.size( )){
                    commodity[idx].triggerEvent(player);
                    commodity.erase(commodity.begin( )+idx) ;
                }
                cout << "I have this items .Do you want it?" << endl;
                cout << "----------------ITEM----------------" <<endl;
                listCommodity( );
                cout << "-------------------------------------" <<endl;
                cout << "Enter the index of want item or Enter -1 to quit : ";

            }while (cin >> idx && idx != -1) ;

            return true;
    }

    //set and get functions
    void NPC::setScript (string script) {
            this -> script = script ;
    }

    void NPC::setCommodity (vector<Item> com) {
            this -> commodity = com ;
    }

    string NPC::getScript( ) {
            return this ->script ;
    }

    vector<Item> NPC::getCommodity( ) {
            return this ->commodity ;
    }
