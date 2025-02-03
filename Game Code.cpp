 #include <iostream>
#include <cstring>
using namespace std;

class Move;
class Item;
class RestoreHealth;
class BoostAttack;
class BoostDefence;
class Game;
// 1) Character Class
class Character
{
    //Character data members
    string name;
    string type;
    string weak_type;
    double max_health;
    double current_health;
    string status;
    int attack_booster;
    int defence_booster;
    int restore_health;
    double damage;
public:
    //Setters for Character data
    void setName(string n);
    void setType(string t);
    void setWeakType(string w);
    void setMaxHealth(int m);
    void setCurrentHealth(double c);
    void setStatus(string s);
    void setAttackBooster(int a);
    void setDefenceBooster(int d);
    void setRestoreHealth(int f);
    void setDamage(double dam);
    //Getters for Character data
    string getName();
    string getType();
    string getWeakType();
    int getMaxHealth();
    double getCurrentHealth();
    string getStatus();
    int getAttackBooster();
    int getDefenceBooster();
    int getRestoreHealth();
    double getDamage();
};

//Setters for Character data members
void Character::setName(string n)
{
    name=n;
}
void Character::setType(string t)
{
    type=t;
}
void Character::setWeakType(string w)
{
    weak_type=w;
}
void Character::setMaxHealth(int m)
{
    max_health=m;
}
void Character::setCurrentHealth(double c)
{
    current_health=c;
}
void Character::setStatus(string s)
{
    status=s;
}
void Character::setAttackBooster(int a)
{
    attack_booster=a;
}
void Character::setDefenceBooster(int d)
{
    defence_booster=d;
}
void Character::setRestoreHealth(int f)
{
    restore_health=f;
}
void Character::setDamage(double dam)
{
    damage=dam;
}

//Getters for Character data members
string Character::getName()
{
    return name;
}
string Character::getType()
{
    return type;
}
string Character::getWeakType()
{
    return weak_type;
}
int Character::getMaxHealth()
{
    return max_health;
}
double Character::getCurrentHealth()
{
    return current_health;
}
string Character::getStatus()
{
    return status;
}
int Character::getAttackBooster()
{
    return attack_booster;
}
int Character::getDefenceBooster()
{
    return defence_booster;
}
int Character::getRestoreHealth()
{
    return restore_health;
}
double Character::getDamage()
{
    return damage;
}


// 2) Move class
class Move
{
    string type; //fire, water, earth, lightning, wind
    string name;
public:
    Move();
    string getName();
    string getType();
    //Move Functions
    void move1(Character &a, Character &b);
    void move2(Character &a, Character &b);
    void move3(Character &a, Character &b);
    void move4(Character &a, Character &b);
};
Move::Move()
{
    name="";
    type="";
}
string Move::getName()
{
    return name;
}
string Move::getType()
{
    return type;
}

//Move 1 Function
void Move::move1(Character &a, Character &b)
{
    cout<<"You choose to "<<a.getType()<<" Ball on "<<b.getName()<<endl;
    if(a.getType()==b.getWeakType())
    {
        //If weak type matches then maximum damage
        cout<<"Maximum Damage, you hit opponents weak type! Damage x2"<<endl;
        b.setCurrentHealth(b.getCurrentHealth()-(a.getDamage()*2));
    }
    else
    {
        cout<<"Damage! "<<a.getDamage()<<endl;
        b.setCurrentHealth(b.getCurrentHealth()-a.getDamage());
    }
}
//Move 2 Function
void Move::move2(Character &a, Character &b)
{
    cout<<"BAAMMMM!! You choose to Fly Punch "<<b.getName()<<endl;
    cout<<"Damage! +10\n"<<"Total Damage: "<<a.getDamage()+10<<endl;
    b.setCurrentHealth(b.getCurrentHealth()-(a.getDamage()+10));
}
//Move 3 Function
void Move::move3(Character &a, Character &b)
{
    cout<<"SMAASHH!! You choose to Head Smash "<<b.getName()<<endl;
    cout<<"Damage! +10\n"<<"Total Damage: "<<a.getDamage()+10<<endl;
    b.setCurrentHealth(b.getCurrentHealth()-(a.getDamage()+10));
}
//Move 4 Function
void Move::move4(Character &a, Character &b)
{
    try
    {
        if(b.getAttackBooster()==1 || b.getDefenceBooster()==1)
        {
            cout<<"You Cast Spell on "<<b.getName()<<endl;
            cout<<b.getName()<<" cannot use Attack Booster and Defence Booster now."<<endl;
            b.setAttackBooster(0);
            b.setDefenceBooster(0);
        }
        else
        {
            throw(555);
        }
    }
    //Exception Handling for when the Attack and Defence Booster are already zero
    catch(...)
    {
        cout<<"The Attack Booster and Defence Booster are already 0 for "<<b.getName()<<endl;
        cout<<a.getName()<<" wasted the turn."<<endl;
    }

}


// 3) Player class
class Player
{
    Character char1;
    Character char2;
    RestoreHealth *restore_health;
    BoostAttack *boost_attack;
    BoostDefence *boost_defence;
    Item *items[3];
public:
    //Contructors
    Player();
    Player(Character &a,Character &b);
    //Setters
    void setChar1(Character &a);
    void setChar2(Character &b);
    void setItem();
    //Getters
    Character getChar1();
    Character getChar2();
    //Display Functions
    void movesDisplayChar1(Character &w,Character &w1);
    void movesDisplayChar2(Character &x,Character &x1);
    void itemsDisplay(Character &a, Character &b);
    void attackChar1(Character &y,Character &y1);
    void attackChar2(Character &z,Character &z1);
    void useRestoreHealth(Character &a);
    void useBoostAttack(Character &a);
    void useBoostDefence(Character &a,Character &b);
};
Player::Player()
{
}
//Paramerterized Constructor
Player::Player(Character &a,Character &b)
{
    char1=a;
    char2=b;
}
//Setters
void Player::setChar1(Character &a)
{
    char1=a;
}
void Player::setChar2(Character &b)
{
    char2=b;
}

//Getters
Character Player::getChar1()
{
    return char1;
}
Character Player::getChar2()
{
    return char2;
}
//Display Functions
void Player::attackChar1(Character &y,Character &y1)
{
    movesDisplayChar1(y,y1);
}
void Player::attackChar2(Character &z,Character &z1)
{
    movesDisplayChar1(z,z1);
}
//Displaying Moves for Player 1
void Player::movesDisplayChar1(Character &w,Character &w1)
{
    Move a;
    int select;
    try
    {
        cout<<"Please choose the move you want to select."<<endl;
        cout<<"1) "<<w.getType()<<" Ball"<<endl;
        cout<<"2) Flying Punch"<<endl;
        cout<<"3) Head Smash"<<endl;
        cout<<"4) Attack and Defence removing spell"<<endl;
        cin>>select;
        if(select>4 || select<1)
        {
            throw(select);
        }
        else if(select==1)
        {
            a.move1(w,w1);
        }
        else if(select==2)
        {
            a.move2(w,w1);
        }
        else if(select==3)
        {
            a.move3(w,w1);
        }
        else if(select==4)
        {
            a.move4(w,w1);
        }
    }
    //Exception Handling
    catch(int b)
    {
        cout<<"Please enter a valid option."<<endl;
        movesDisplayChar1(w,w1);
    }

}
//Displaying Moves for Player 2
void Player::movesDisplayChar2(Character &x,Character &x1)
{
    Move a;
    int select;
    try
    {
        cout<<"Please choose the move you want to select."<<endl;
        cout<<"1) "<<x.getType()<<" Ball"<<endl;
        cout<<"2) Flying Punch"<<endl;
        cout<<"3) Head Smash"<<endl;
        cout<<"4) Attack Booster and Defence Booster removing spell"<<endl;
        cin>>select;
        if(select>4 || select<1)
        {
            throw(select);
        }
        else if(select==1)
        {
            a.move1(x,x1);
        }
        else if(select==2)
        {
            a.move2(x,x1);
        }
        else if(select==3)
        {
            a.move3(x,x1);
        }
        else if(select==4)
        {
            a.move4(x,x1);
        }
    }
    //Exception Handling
    catch(int b)
    {
        cout<<"Please enter a valid option."<<endl;
        movesDisplayChar2(x,x1);
    }
}
//Items Display Function
void Player::itemsDisplay(Character &a, Character &b)
{
    Player obj;
    int select;
    cout<<"Choose an item you want to use."<<endl;
    cout<<"Note that each item can only be used once."<<endl;
    try
    {
        cout<<"1) Restore Health\n2) Use Attack Booster\n3) Use Defence Booster"<<endl;
        cin>>select;
        if(select>3 || select<1)
        {
            throw(select);
        }
        else if(select==1)
        {
            if(a.getRestoreHealth()==0)
            {
                throw(555); //Error message if item already used
            }
            else
            {
                obj.useRestoreHealth(a);
            }
        }
        else if(select==2)
        {
            if(a.getAttackBooster()==0)
            {
                throw(555); //Error message if item already used
            }
            else
            {
                obj.useBoostAttack(a);
            }

        }
        else if(select==3)
        {
            if(a.getDefenceBooster()==0)
            {
                throw(555); //Error message if item already used
            }
            else
            {
                obj.useBoostDefence(a,b);
            }
        }
    }
    //Exception Handling
    catch(int num)
    {
        cout<<"Either you have already used this item or you entered a wrong input"<<endl;
        itemsDisplay(a,b);
    }
}
void Player::useRestoreHealth(Character &a)
{
    a.setCurrentHealth(a.getMaxHealth());
    cout<<"Health of "<<a.getName()<<" set to Full back again"<<endl;
    a.setRestoreHealth(0);
}
void Player::useBoostAttack(Character &a)
{
    cout<<"Attack Booster used for "<<a.getName()<<endl;
    cout<<"Attack per Damage +10"<<endl;
    a.setDamage(a.getDamage()+10);
    a.setAttackBooster(0);
}
void Player::useBoostDefence(Character &a,Character &b)
{
    cout<<"Defence Booster used for "<<a.getName()<<endl;
    cout<<"Opponent Damage -10 per Attack"<<endl;
    b.setDamage(b.getDamage()-10);
    a.setDefenceBooster(0);
}

// 4) Game Class
class Game
{
    Character a,b,c,d,e,f;
    Character arr[6]={a,b,c,d,e,f};
    Move the_move;
public:
    Game();
    void mainMenu(Player &x);
    void player1Turn(Character &y,Character &y1);
    void player2Turn(Character &z,Character &z1);
};
//Default Constructor for setting Character data for all Pokemons
Game::Game()
{
    //Setting Pokemon a (Charizard)
    a.setName("Charizard");
    a.setType("fire");
    a.setWeakType("water");
    a.setMaxHealth(200);
    a.setCurrentHealth(200);
    a.setStatus("alive");
    a.setAttackBooster(1);
    a.setDefenceBooster(1);
    a.setRestoreHealth(1);

    a.setDamage(20);
    //Setting Pokemon b (Pikachu)
    b.setName("Pikachu");
    b.setType("lightning");
    b.setWeakType("earth");
    b.setMaxHealth(100);
    b.setCurrentHealth(100);
    b.setStatus("alive");
    b.setAttackBooster(1);
    b.setDefenceBooster(1);
    b.setDamage(35);
    b.setRestoreHealth(1);
    //Setting Pokemon c (Squirtle)
    c.setName("Squirtle");
    c.setType("water");
    c.setWeakType("lightning");
    c.setMaxHealth(90);
    c.setCurrentHealth(90);
    c.setStatus("alive");
    c.setAttackBooster(1);
    c.setDefenceBooster(1);
    c.setDamage(40);
    c.setRestoreHealth(1);
    //Setting Pokemon d (Onix)
    d.setName("Onix");
    d.setType("earth");
    d.setWeakType("water");
    d.setMaxHealth(120);
    d.setCurrentHealth(120);
    d.setStatus("alive");
    d.setAttackBooster(1);
    d.setDefenceBooster(1);
    d.setDamage(30);
    d.setRestoreHealth(1);
    //Setting Pokemon e (Cloudlet)
    e.setName("Cloudlet");
    e.setType("wind");
    e.setWeakType("fire");
    e.setMaxHealth(150);
    e.setCurrentHealth(150);
    e.setStatus("alive");
    e.setAttackBooster(1);
    e.setDefenceBooster(1);
    e.setDamage(25);
    e.setRestoreHealth(1);
    //Setting Pokemon e (Arcanine)
    f.setName("Arcanine");
    f.setType("fire");
    f.setWeakType("water");
    f.setMaxHealth(170);
    f.setCurrentHealth(170);
    f.setStatus("alive");
    f.setAttackBooster(1);
    f.setDefenceBooster(1);
    f.setDamage(20);
    f.setRestoreHealth(1);
}

//Main Menu Function
void Game::mainMenu(Player &x)
{
    int select;
    try
    {
        //Displaying the selection of Pokemon for Player 1
        cout<<"Player 1 please choose your Pokemon: "<<endl;
        cout<<"1) "<<a.getName()<<"  Type: "<<a.getType()<<"       Weak Type: "<<a.getWeakType()<<endl;
        cout<<"2) "<<b.getName()<<"    Type: "<<b.getType()<<"  Weak Type: "<<b.getWeakType()<<endl;
        cout<<"3) "<<c.getName()<<"   Type: "<<c.getType()<<"      Weak Type: "<<c.getWeakType()<<endl;
        cout<<"4) "<<d.getName()<<"       Type: "<<d.getType()<<"      Weak Type: "<<d.getWeakType()<<endl;
        cout<<"5) "<<e.getName()<<"   Type: "<<e.getType()<<"       Weak Type: "<<e.getWeakType()<<endl;
        cout<<"6) "<<f.getName()<<"   Type: "<<f.getType()<<"       Weak Type: "<<f.getWeakType()<<endl;
        cin>>select;
        if(select>6 || select<1)
        {
            throw(select);
        }
        else if(select==1)
        {
            cout<<"You seem like fan of heat, You chose "<<a.getName()<<" of type "<<a.getType();
            cout<<endl;
            x.setChar1(a);

        }
        else if(select==2)
        {
            cout<<"Feel the Shock, You chose "<<b.getName()<<" of type "<<b.getType();
            cout<<endl;
            x.setChar1(b);
        }
        else if(select==3)
        {
            cout<<"Watch out of the incoming flood ,You chose "<<c.getName()<<" of type "<<a.getType();
            cout<<endl;
            x.setChar1(c);
        }
        else if(select==4)
        {
            cout<<"Feel the Earthquake, You chose "<<d.getName()<<" of type "<<d.getType();
            cout<<endl;
            x.setChar1(d);
        }
        else if(select==5)
        {
            cout<<"Tornado incoming, You chose "<<e.getName()<<" of type "<<e.getType();
            cout<<endl;
            x.setChar1(e);
        }
        else if(select==6)
        {
            cout<<"Things just got heated up, You chose "<<f.getName()<<" of type "<<f.getType();
            cout<<endl;
            x.setChar1(f);
        }
    }
    //Exception Handling
    catch(int a)
    {
        cout<<"Please enter a valid input."<<endl;
        mainMenu(x);
    }

    try
    {
        //Displaying the selection of Pokemon for Player 2
        cout<<endl<<endl;
        cout<<"Player 2 please choose your Pokemon: "<<endl;
        cout<<"1) "<<a.getName()<<"  Type: "<<a.getType()<<"       Weak Type: "<<a.getWeakType()<<endl;
        cout<<"2) "<<b.getName()<<"    Type: "<<b.getType()<<"  Weak Type: "<<b.getWeakType()<<endl;
        cout<<"3) "<<c.getName()<<"   Type: "<<c.getType()<<"      Weak Type: "<<c.getWeakType()<<endl;
        cout<<"4) "<<d.getName()<<"       Type: "<<d.getType()<<"      Weak Type: "<<d.getWeakType()<<endl;
        cout<<"5) "<<e.getName()<<"   Type: "<<e.getType()<<"       Weak Type: "<<e.getWeakType()<<endl;
        cout<<"6) "<<f.getName()<<"   Type: "<<f.getType()<<"       Weak Type: "<<f.getWeakType()<<endl;
        cin>>select;
        if(select>6 || select<1)
        {
            throw(select);
        }
        else if(select==1)
        {
            cout<<"You seem like fan of heat, You chose "<<a.getName()<<" of type "<<a.getType();
            cout<<endl;
            x.setChar2(a);

        }
        else if(select==2)
        {
            cout<<"Feel the Shock, You chose "<<b.getName()<<" of type "<<b.getType();
            cout<<endl;
            x.setChar2(b);
        }
        else if(select==3)
        {
            cout<<"Watch out of the incoming flood ,You chose "<<c.getName()<<" of type "<<a.getType();
            cout<<endl;
            x.setChar2(c);
        }
        else if(select==4)
        {
            cout<<"Feel the Earthquake, You chose "<<d.getName()<<" of type "<<d.getType();
            cout<<endl;
            x.setChar2(d);
        }
        else if(select==5)
        {
            cout<<"Tornado incoming, You chose "<<e.getName()<<" of type "<<e.getType();
            cout<<endl;
            x.setChar2(e);
        }
        else if(select==6)
        {
            cout<<"Things just got heated up, You chose "<<f.getName()<<" of type "<<f.getType();
            cout<<endl;
            x.setChar2(f);
        }
    }
    //Exception Handling
    catch(int a)
    {
        cout<<"Please enter a valid input."<<endl;
        mainMenu(x);
    }
    cout<<endl<<endl<<"Battle Begins!"<<endl<<endl;
}

//Player 1 Turn Function
void Game::player1Turn(Character &y,Character &y1)
{
    int select;
    Player player_obj;
    cout<<endl;
    cout<<y.getName()<<"'s Turn."<<endl;
    cout<<"1) Attack\n2) Use Item: "<<endl;
    cin>>select;
    try
    {
        if(select>2 || select<1)
        {
            throw(select);
        }
        else if(select==1)
        {
            //Calling attack Function
            player_obj.attackChar1(y,y1);
        }
        else if(select==2)
        {
            player_obj.itemsDisplay(y,y1);
        }
    }
    //Exception Handling
    catch(int a)
    {
        cout<<"Error! Enter a valid option."<<endl;
        cout<<endl;
        player1Turn(y,y1);
    }
}

//Player Two Turn Function
void Game::player2Turn(Character &z,Character &z1)
{
    int select;
    Player player_obj;
    cout<<endl;
    cout<<z.getName()<<"'s Turn."<<endl;
    cout<<"1) Attack\n2) Use Item: "<<endl;
    cin>>select;
    try
    {
        if(select>2 || select<1)
        {
            throw(select);
        }
        else if(select==1)
        {
            //Calling attack function for Player 2
            player_obj.attackChar2(z,z1);
        }
        else if(select==2)
        {
            player_obj.itemsDisplay(z,z1);;
        }
    }
    //Exception Handling
    catch(int a)
    {
        cout<<"Error! Enter a valid option."<<endl;
        cout<<endl;
        player2Turn(z,z1);
    }
}



// 5) Item Abstract class
class Item
{
public:
    string name;
    virtual void use()=0;
};

// 1)Derived class of Item Class to restore health
class RestoreHealth: public Item
{
public:
    RestoreHealth();
   void use(Character &a);
};
RestoreHealth::RestoreHealth()
{
    name="Restore Health";
}
void RestoreHealth::use(Character &a)
{
    a.setCurrentHealth(a.getMaxHealth());
}
// 2)Derived class of Item Class to Boost Attack
class BoostAttack: public Item
{
public:
    void use(Character &a);
};
void BoostAttack::use(Character &a)
{
    cout<<"Attack Booster used for "<<a.getName()<<endl;
    cout<<"Attack per Damage +10"<<endl;
    a.setDamage(a.getDamage()+10);
    a.setAttackBooster(0);
}
//2)Derived class of Item Class to Boost Defence
class BoostDefence:public Item
{
    public:
    void use(Character &a,Character &b);
};
void BoostDefence::use(Character &a, Character &b)
{
    cout<<"Defence Booster used for "<<a.getName()<<endl;
    cout<<"Opponent Damage -10 per Attack"<<endl;
    b.setDamage(b.getDamage()-10);
    a.setDefenceBooster(0);
}

//Main Function
int main()
{
    system("Color 03");
    int select;
    string ss;
    Player player_obj;              //Creating Player class object
    cout<<"Pokemon Battle!"<<endl<<endl; //Starting menu display

    //Intrsuctions
    cout<<"Instructions: "<<endl;
    cout<<"Pokemon Battle is a 1v1 Two Player Battle Game."<<endl;
    cout<<"Each Player will use 1 Pokemon out of a selection of 6 Pokemons."<<endl;
    cout<<"Every Pokemon has Different Type ((fire, water, earth, lightning, wind), Weak Type, Damage per Attack, and Health."<<endl;
    cout<<"Pokemons with Higher Health have less Damage on each attack and vice versa."<<endl;
    cout<<"Each Pokemon also has a selection of once use only Items like Health Booster, Attack Booster etc. (Use them wisely) "<<endl;
    cout<<endl<<"Good Luck!"<<endl<<endl;
    cout<<"Press any button to start!"<<endl;
    cin>>ss;
    cout<<endl<<endl;
    Game obj;
    obj.mainMenu(player_obj);           //Calling Main Menu Display Function

    //Creating two Character variables and giving them Char1 and Char2 objects
    Character a =player_obj.getChar1();
    Character b =player_obj.getChar2();
    while(1)
    {
        system("Color 07");
        //Player 1 Turn
        obj.player1Turn(a,b);
        //Health Display
        cout<<a.getName()<<" Health: "<<a.getCurrentHealth()<<endl;
        cout<<b.getName()<<" Health: "<<b.getCurrentHealth()<<endl;
        if(b.getCurrentHealth()<=0)
        {
            //If Player 2 Health Finishes declaring Player 1 as Winner
            cout<<b.getName()<<" is defeated."<<endl;
            cout<<"Congratulations "<<a.getName()<<endl;
            return 0;
        }
        else
        {
            //Player 2 Turn
            obj.player2Turn(b,a);
            if(a.getCurrentHealth()<=0)
            {
                cout<<endl;
                //If Player 1 Health Finishes declaring Player 2 as Winner
                cout<<a.getName()<<" is defeated."<<endl;
                cout<<"Congratulations "<<b.getName()<<endl;
                return 0;

            }
            //Health Display after Player 2 turn
            cout<<a.getName()<<" Health: "<<a.getCurrentHealth()<<endl;
            cout<<b.getName()<<" Health: "<<b.getCurrentHealth()<<endl;
        }
    }
}



