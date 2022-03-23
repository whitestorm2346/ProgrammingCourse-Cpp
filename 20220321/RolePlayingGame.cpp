#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

class Monster;
class Player;
class NPC;

class Attack
{
protected:
    int ATK;
    int hitRate; // unit: %

public:
    Attack(int ATK, int hitRate);

    void attack(Player&);
    void attack(Monster&);
    void attack(NPC&);
};

class Character: public Attack
{
protected:
    std::string role;
    int HP;
    int currHP;
    int Exp;
    int Lv;

public:
    Character(std::string role, int HP, int ATK, int hitRate);
    ~Character(){}

    void state();
    void upgrade();
    void respown();
    bool hurt(int damage);
};

class Monster: public Character
{
    bool angryMode;
    bool berserkMode;

public:
    Monster();
    ~Monster(){}

    void checkMode();
    void attack(Player& player);
    void attack(Monster& monster);
    void attack(NPC& npc);
};

class Player: public Character
{
public:
    Player();
    ~Player(){}

    void attack(Monster&);
};

class NPC: public Character
{
public:
    NPC();
    ~NPC(){}
};

int main()
{
    std::srand(std::time(NULL));

    NPC* npc = new NPC();
    Player* player = new Player();
    Monster* monster = new Monster();

    std::cout<< "< NPC >\n";
    npc->state();

    std::cout<< "\n< Player >\n";
    player->state();

    std::cout<< "\n< monster >\n";
    monster->state();

    delete npc;
    delete player;
    delete monster;

    return 0;
}

Attack::Attack(int ATK, int hitRate)
{
    this->ATK = ATK;
    this->hitRate = hitRate;
}
void Attack::attack(Player& player)
{
    if((rand() % 100) < hitRate)
    {
        if(player.hurt(ATK)) player.respown();

        std::cout<< "Player is under attack......\n";
    }
    else std::cout<< "Misses the attack......\n";
}
void Attack::attack(Monster& monster)
{
    if((rand() % 100) < hitRate)
    {
        if(monster.hurt(ATK)) monster.respown();

        std::cout<< "Player is under attack......\n";
    }
    else std::cout<< "Misses the attack......\n";
}
void Attack::attack(NPC& npc)
{
    if((rand() % 100) < hitRate)
    {
        if(npc.hurt(ATK)) npc.respown();

        std::cout<< "NPC is under attack......\n";
    }
    else std::cout<< "Misses the attack......\n";
}
Character::Character(std::string role, int HP, int ATK, int hitRate): Attack(ATK, hitRate)
{
    this->role = role;
    this->HP = HP;
    this->currHP = HP;
    this->Exp = 0;
    this->Lv = 1;
}
void Character::state()
{
    std::cout<< "Level: " << Lv << '\n';
    std::cout<< "Exp: " << Exp << "/100\n";
    std::cout<< "HP:  " << currHP << '/' << HP << '\n';
    std::cout<< "ATK: " << ATK << '\n';
}
void Character::upgrade()
{
    Lv++;
    HP += 10;

    if(Lv % 3 == 1) ATK++;
}
void Character::respown()
{
    std::cout<< role << " respowned......\n";

    currHP = HP;
    Exp = 0;
}
bool Character::hurt(int damage)
{
    HP -= damage;

    if(HP <= 0)
    {
        std::cout<< role << " is dead......\n";

        return true;
    }
    else return false;
}
Player::Player(): Character("Player", 100, 1, 80)
{

}
void Player::attack(Monster& monster)
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
        else

        std::cout<< "Monster is under attack......\n";
    }
    else std::cout<< "Misses the attack......\n";
}
Monster::Monster(): Character("Monster", 200, 10, 50)
{
    angryMode = false;
    berserkMode = false;
}
void Monster::checkMode()
{
    if((static_cast<double>(currHP) / HP) <= 0.2) berserkMode = angryMode = true;
    else if((static_cast<double>(currHP) / HP) <= 0.5) angryMode = true, berserkMode = false;
    else berserkMode = angryMode = false;
}
void Monster::attack(Player& player)
{
    int temp = ATK;

    if(berserkMode) ATK *= 3;
    else if(angryMode) ATK *= 2;

    Character::attack(player);

    ATK = temp;
}
void Monster::attack(Monster& monster)
{
    int temp = ATK;

    if(berserkMode) ATK *= 3;
    else if(angryMode) ATK *= 2;

    Character::attack(monster);

    ATK = temp;
}
void Monster::attack(NPC& npc)
{
    int temp = ATK;

    if(berserkMode) ATK *= 3;
    else if(angryMode) ATK *= 2;

    Character::attack(npc);

    ATK = temp;
}
NPC::NPC(): Character("NPC", 150, 5, 60)
{

}
