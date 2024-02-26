#include "Dungeon.h"

bool Dungeon::undone = true;
Dungeon::Dungeon(){}

void Dungeon::createPlayer(){
        string s =
        "// ##    ##    ###    ########  ##     ## ########  #######\n"
        "// ###   ##   ## ##   ##     ## ##     ##    ##    ##     ##\n"
        "// ####  ##  ##   ##  ##     ## ##     ##    ##    ##     ##\n"
        "// ## ## ## ##     ## ########  ##     ##    ##    ##     ##\n"
        "// ##  #### ######### ##   ##   ##     ##    ##    ##     ##\n"
        "// ##   ### ##     ## ##    ##  ##     ##    ##    ##     ##\n"
        "// ##    ## ##     ## ##     ##  #######     ##     #######\n"
        "=================================================================\n"
        "// #####    ##   ##  ##   ##   #####   #######   #####   ##   ##\n"
        "//  ## ##   ##   ##  ###  ##  ##   ##   ##   #  ### ###  ###  ##\n"
        "//  ##  ##  ##   ##  #### ##  ##        ##      ##   ##  #### ##\n"
        "//  ##  ##  ##   ##  #######  ## ####   ####    ##   ##  #######\n"
        "//  ##  ##  ##   ##  ## ####  ##   ##   ##      ##   ##  ## ####\n"
        "//  ## ##   ##   ##  ##  ###  ##   ##   ##   #  ### ###  ##  ###\n"
        "// #####     #####   ##   ##   #####   #######   #####   ##   ##\n";
        cout << s;
        string name;
        cout << "Please Input Your Name: ";
        cin >> name;
        player = Player(name,100,40, 60);
        cout << "Hello, Ninja " << name << endl;
        player.triggerEvent(&player);

}

void Dungeon::createMap(){

        //monsters
        Monster* matatabi = new Monster("Matatabi",20, 20, 30);
        Monster* shukaku = new Monster("Shukaku",50,50,40);
        Monster* kokuo = new Monster("Kokuo",80,50,60);
       //monster boss
        Monster* kurama = new Monster("Kurama",100,80,70);
        kurama->setIsBoss(true);

        //NPC
        NPC* kakashi = new NPC("Kakashi","Hi ! I'm Hatake Kakashi .\nWelcome to enter Konohagakure's dungeon to improve your Jutsu.\nTo leave this dungeon you have to Fuinn the Kurama.\nHere is your backpack.\n",vector<Item>{Item("Chidori","weapon",0,60,0)});
        NPC* gai = new NPC("Gai", "Hi ! I'm Gai.\nOne of your teacher in Konohagakure.\nSeems that you beat the matatabi just now!\nHope you can finish the test of the dungeon.",vector<Item>{Item("Paper_Bomb","weapon",0,30,0)});
        NPC* sakura = new NPC("Sakura","Hi ,I'm Sakura.\nI am the classamate in class 9th.\nGo ahead to finish your adventure.\n",vector<Item>{Item("Ramen","weapon",0,0,10)});
        NPC* jiraiya = new NPC("Jiraiya","Hi!i am Jiraiya, you can also call me ero senjin.\nWow!You beat the Shukaku,there are still a lot of  monsters waiting for you.\nWish you can escape from this complex dungeon.\n",vector<Item>{Item("Rasengan","weapon",0,80,0)});
        NPC* sasuke = new NPC("Sasuke","Long time no see!\nI can't believe that you can conquer that monsters.\nI will keep finding my brother Itachi.\nSee you next time!\n ",vector<Item>{Item("Kunai","weapon",0,10,10)});

        Room* initRoom = new Room(false,0,vector<Object*>{kakashi});
        Room* sakuraRoom = new Room (false,1,vector<Object*>{sakura,new Item("Big_Ramen","weapon",0,0,20)});
        Room* matatabiRoom = new Room(false,2,vector<Object*>{matatabi});
        Room* gaiRoom = new Room(false,3,vector<Object*>{gai,new Item("Shuriken","weapon",0,10,0)});
        Room* shukakuRoom = new Room (false,4,vector<Object*>{shukaku});
        Room* jiraiyaRoom = new Room(false,5,vector<Object*>{jiraiya});
        Room* kokuoRoom = new Room(false,6,vector<Object*>{kokuo,new Item("Shuriken","weapon",0,10,0)});
        Room* sasukeRoom = new Room(false,7,vector<Object*>{sasuke,new Item("Kunai","weapon",0,10,10)});
        Room* kuramaRoom = new Room(true,8,vector<Object*>{kurama});

        //initroom
        initRoom->setUpRoom(matatabiRoom);
        initRoom->setLeftRoom(sakuraRoom);
        //matabiroom
        matatabiRoom->setDownRoom(initRoom);
        matatabiRoom->setRightRoom(gaiRoom);
        //sakuraroom
        sakuraRoom->setRightRoom(initRoom);
        //gairoom
        gaiRoom->setLeftRoom(matatabiRoom);
        gaiRoom->setDownRoom(shukakuRoom);
        //shukakuroom
        shukakuRoom->setUpRoom(gaiRoom);
        shukakuRoom->setLeftRoom(jiraiyaRoom);
        //jirayaRoom
        jiraiyaRoom->setDownRoom(kokuoRoom);
        jiraiyaRoom->setRightRoom(shukakuRoom);
        //kokuoRoom
        kokuoRoom->setUpRoom(jiraiyaRoom);
        kokuoRoom->setRightRoom(sasukeRoom);
        //sasukeroom
        sasukeRoom->setLeftRoom(kokuoRoom);
        sasukeRoom->setUpRoom(kuramaRoom);
        //kuramaroom
        kuramaRoom->setDownRoom(sasukeRoom);

        rooms.push_back(initRoom);
        rooms.push_back(sakuraRoom);
        rooms.push_back(matatabiRoom);
        rooms.push_back(gaiRoom);
        rooms.push_back(shukakuRoom);
        rooms.push_back(jiraiyaRoom);
        rooms.push_back(kokuoRoom);
        rooms.push_back(sasukeRoom);
        rooms.push_back(kuramaRoom);

        player.setCurrentRoom(initRoom);

}

void Dungeon::handleMovement(){
        map<char,Room*>avaRoom;
        if(player.getCurrentRoom()->getUpRoom()!=nullptr|| player.getCurrentRoom() -> getDownRoom() != nullptr || player.getCurrentRoom() -> getLeftRoom() != nullptr || player.getCurrentRoom() -> getRightRoom() != nullptr){
            if(player.getCurrentRoom()->getUpRoom()!=nullptr){
                avaRoom['U'] = avaRoom['u'] = player.getCurrentRoom()->getUpRoom();
                cout << "(U)p Room" << endl ;
            }
            if(player.getCurrentRoom() -> getDownRoom() != nullptr){
                avaRoom['D'] = avaRoom['d'] = player.getCurrentRoom() -> getDownRoom();
                cout << "(D)own Room" << endl;
            }
            if(player.getCurrentRoom() -> getLeftRoom() != nullptr){
                avaRoom['L'] = avaRoom['l'] = player.getCurrentRoom() -> getLeftRoom();
                cout << "(L)eft Room" << endl;
            }
            if(player.getCurrentRoom() -> getRightRoom() != nullptr){
                avaRoom['R'] = avaRoom['r'] = player.getCurrentRoom() -> getRightRoom();
                cout << "(R)ight Room" << endl;
            }
            if(player.getCurrentRoom() -> getIsExit() == true){
                avaRoom['E'] = avaRoom['e'] = nullptr;
                cout << "(E)xit" << endl;
            }

            char c;
            do{
                cout << "Which room do you want to go? ";
            } while(cin >> c && avaRoom.find(c) == avaRoom.end());
            if(c == 'E' || c == 'e'){
                cout << "Congratulations! Ninja " << player.getName() << ", you have finished the justu lesson.\nGo other adventures and to be a Hokage .Fire style Fire Ball justu !!!"  << endl;
                player.setCurrentRoom(nullptr);
            } else {
                player.changeRoom(avaRoom[c]);
            }

        }else {
            cout << "Sorry, you can't go anywhere." << endl;
        }
    return;
}

void Dungeon::chooseAction(vector<Object*> objects){
    int idx = 0;
    for(int i=0;i<(int)objects.size();i++){
        if(objects[i]->getTag() == "Monster"){
            handleEvent(objects[i]);
            return;
        }
    }
    cout << "------------------- R O O M -------------------" << endl;
    for(int i=0;i<(int)objects.size();i++){
        cout << idx ++ << ": " << (objects[i]->getTag() == "Item" ? dynamic_cast<Item*>(objects[i])->getType() : objects[i]->getTag()) <<" " << objects[i]->getName() << endl;
    }
    cout << "--------------------------------------------" << endl;
    cout << "(M)ove" << endl;
    cout << "(S)how Status" << endl;
    cout << "(E)quipment" << endl;
    cout << "(Q)uit" << endl;
    char c;
    do{
        cout << "Enter the charcter you want to interact: ";
    } while(cin >> c && !(('0' <= c && c < '0'+(int)objects.size())
        || c == 'M' || c == 'm' || c == 'S' || c == 's' || c == 'E' || c == 'e' || c == 'Q' || c == 'q'));
    if(c == 'M' || c == 'm'){
        handleMovement();
    } else if(c == 'S' || c == 's'){
        player.triggerEvent(&player);
    } else if(c == 'E' || c == 'e'){
        player.equip();
    }  else if(c == 'Q' || c == 'q'){
        exit(0);
    } else {
        handleEvent(objects[c-'0']);
        if(objects[c-'0']->getTag()=="Item"){
            player.getCurrentRoom()->popObject(objects[c-'0']);
        }
    }
}

void Dungeon::handleEvent(Object* object){
        object->triggerEvent(&player);
        return;
}

void Dungeon::startGame(){
        createPlayer();
        createMap();
}

bool Dungeon::checkGameLogic(){
        if(player.getCurrentRoom() == nullptr||player.getCurrentHealth()<=0)return false;
        else {return true;}
}

void Dungeon::runDungeon(){
        startGame();
        while(undone){
                if(checkGameLogic() == false){
                        exit(0);
                }
                chooseAction(player.getCurrentRoom()->getObjects());
        }
}
