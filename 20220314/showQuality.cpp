#include <iostream>
#include <string>

#define HUNTER 0
#define WARRIOR 1
#define PRIEST 2
#define NPC 3

class Character
{
    int HP;  // Health Points
    int AC;  // Armour Class
    int ATK; // Attack Points
    int Dodge;

public:
    Character(int HP, int AC, int ATK, int Dodge);
    ~Character(){}

    void showQuality(int role);
};

class Hunter: public Character
{
public:
    Hunter();
    ~Hunter(){}
};

class Warrior: public Character
{
public:
    Warrior();
    ~Warrior(){}
};

class Priest: public Character
{
public:
    Priest();
    ~Priest(){}
};

class NonPlayerCharacter: public Character
{
public:
    NonPlayerCharacter();
    ~NonPlayerCharacter(){}
};

int main()
{
    Hunter* hunter = new Hunter();
    Warrior* warrior = new Warrior();
    Priest* priest = new Priest();
    NonPlayerCharacter* npc = new NonPlayerCharacter();

    hunter->showQuality(HUNTER);
    warrior->showQuality(WARRIOR);
    priest->showQuality(PRIEST);
    npc->showQuality(NPC);

    delete npc;
    delete hunter;
    delete warrior;
    delete priest;

    return 0;
}

Character::Character(int HP, int AC, int ATK, int Dodge)
{
    this->HP = HP;
    this->AC = AC;
    this->ATK = ATK;
    this->Dodge = Dodge;
}
void Character::showQuality(int role)
{
    switch(role)
    {
        case HUNTER: std::cout<< "< Hunter >\n"; break;
        case WARRIOR: std::cout<< "< Warrior >\n"; break;
        case PRIEST: std::cout<< "< Priest >\n"; break;
        case NPC: std::cout<< "< NPC >\n"; break;
    }

    std::cout<< "HP: " << HP << '\n';
    std::cout<< "AC: " << AC << '\n';
    std::cout<< "ATK: " << ATK << '\n';
    std::cout<< "Dodge: " << Dodge << "\n\n";
}
Hunter::Hunter(): Character(150, 3, 4, 40)
{

}
Warrior::Warrior(): Character(200, 4, 3, 30)
{

}
Priest::Priest(): Character(120, 2, 2, 20)
{

}
NonPlayerCharacter::NonPlayerCharacter(): Character(100, 1, 1, 10)
{

}
