#include <iostream>

class Object
{
public:
    void Action()
    {
        std::cout<< "Do nothing......\n";
    }
    void MoveTo(int x, int y)
    {
        std::cout<< "Walking to location(" << x << "," << y << ")\n";
    }
    void Attack()
    {
        std::cout<< "Attack.......\n";
    }
};

class NPC: public Object
{

};

class Player: public Object
{
public:
    void Action()
    {
        MoveTo(10,20);
    }
    void Attack(){
        std::cout<< "Casting magic......\n";

        Object::Attack();
    }
};

class Monster: public Object{
public:
    void MoveTo(int x, int y){
        std::cout<< "Flying to location(" << x << "," << y << ")\n";
    }
    void Action(){
        MoveTo(10,20);
        Attack();
    }
};

class Building: public Object{

};

int main(){
	NPC npc;
	Player player;
	Monster monster;
	Building building;

	std::cout<< "NPC: ";
    npc.Action();

    std::cout<< "Player: ";
    player.Action();

    std::cout<< "Monster: ";
    monster.Action();

    std::cout<< "Player: fight back....\n";
    player.Attack();

    std::cout<<"Building: ";
    building.Action();

	return 0;
}
