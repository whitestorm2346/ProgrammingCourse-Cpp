#include <iostream>
#include <cstdlib>
#include <ctime>

class Monster;
class Player;
class NPC;

class Character
{
protected:
    int HP;
    int ATK;
    int hitRate; // unit: %
    int Exp;
    int Lv;

public:
    Character(int HP, int ATK, int hitRate);
    ~Character(){}

    void state();
    void attack(Player& player);
    void attack(Monster& monster);
    void attack(NPC& npc);
    void upgrade();
    bool hurt(int damage);
};

class Monster: public Character
{
public:
    Monster();
    ~Monster(){}

    void respown();
};

class Player: public Character
{
public:
    Player();
    ~Player(){}

    void respown();
};

class NPC: public Character
{
public:
    NPC();
    ~NPC(){}

    void respown();
};

int main()
{
    std::srand(std::time(NULL));

    NPC* npc = new NPC();
    Player* player = new Player();
    Monster* monster = new Monster();

    delete npc;
    delete player;
    delete monster;

    return 0;
}

Character::Character(int HP, int ATK, int hitRate)
{
    this->HP = HP;
    this->ATK = ATK;
    this->hitRate = hitRate;
    this->Exp = 0;
    this->Lv = 1;
}
void Character::state()
{
    std::cout<< "HP:  " << HP << '\n';
    std::cout<< "ATK: " << ATK << '\n';
}
void Character::attack(Player& player)
{
    if((rand() % 100) < hitRate)
    {
        if(player.hurt(ATK)) player.respown();

        std::cout<< "player under attack......\n";
    }
    else std::cout<< "miss......\n";
}
void Character::attack(Monster& monster)
{
    if((rand() % 100) < hitRate)
    {
        if(monster.hurt(ATK))
        {
            monster.respown();

            Exp += 10;

            if(Exp >= 100)
            {
                Exp -= 100;

                upgrade();
            }
        }

        std::cout<< "monster under attack......\n";
    }
    else std::cout<< "miss......\n";
}
void Character::attack(NPC& npc)
{
    if((rand() % 100) < hitRate)
    {
        if(npc.hurt(ATK)) npc.respown();

        std::cout<< "NPC under attack......\n";
    }
    else std::cout<< "miss......\n";
}
void Character::upgrade()
{
    Lv++;
    HP += 10;

    if(Lv % 3 == 1) ATK++;
}
bool Character::hurt(int damage)
{
    HP -= damage;

    if(HP <= 0)
    {
        std::cout<< "die......\n";

        return true;
    }
    else return false;
}
Player::Player(): Character(100, 1, 80)
{

}
void Player::respown()
{
    Lv = 1;
    Exp = 0;
    HP = 100;
    ATK = 1;
}
Monster::Monster(): Character(200, 10, 50)
{

}
void Monster::respown()
{
    Lv = 1;
    Exp = 0;
    HP = 200;
    ATK = 10;
}
NPC::NPC(): Character(150, 5, 60)
{

}
void NPC::respown()
{
    Lv = 1;
    Exp = 0;
    HP = 150;
    ATK = 60;
}
