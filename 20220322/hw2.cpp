#include <iostream>
#include <string>

class Player;
class Monster;

class Object
{
protected:
    std::string name;
    int dmg;

public:
    Object(){
        name = "Object";
        dmg = 0;
    }
    Object(int x){
        name = "Object";
        dmg = x;
    }
    Object(std::string n, int x){
        name = n;
        dmg = x;
    }

    void Action(){
        std::cout<< "Do nothing......\n";
    }
    void MoveTo(int x, int y){
        std::cout<< "Walking to location(" << x << ',' << y << ")\n";
    }
    void Attack(int dmg){
        std::cout<< "Attack.......\n";
        std::cout<< "Damage: " << dmg << '\n';
    }
    std::string Whoami(){
        return name;
    }
    void InteractWith(Object obj){
        std::cout<< name << " interact with " << obj.Whoami() << '\n';
    }
};

class Player: public Object
{
    int magicDmg;

public:
    Player(): Object("Player", 10){
        magicDmg = 10;
        //cout<<"dmg = "<<dmg<<endl;
        //cout<<"magicDmg = "<<magicDmg<<endl;
    }
    Player(std::string myName): Object(myName,10){
        magicDmg = 10;
        //cout<<"dmg = "<<dmg<<endl;
        //cout<<"magicDmg = "<<magicDmg<<endl;
    }

    void Action(){
        MoveTo(10, 20);
        Attack();
    }
    void Attack(){
        std::cout<< "Casting magic......\n";
        Object::Attack(dmg + magicDmg);
    }
    void InteractWith(Player player){
        std::cout<< name << " says Hi to " << player.Whoami() << '\n';
    }
    void InteractWith(Monster monster);
};

class Monster: public Object
{
public:
    Monster(): Object("Monster", 20){
        //cout<<"dmg = "<<dmg<<endl;
    }
    Monster(std::string myName): Object(myName, 20){
        //cout<<"dmg = "<<dmg<<endl;
    }
    void MoveTo(int x, int y){
        std::cout<< "Flying to location(" << x << ',' << y << ")\n";
    }
    void Action(){
        MoveTo(10, 20);
        Attack(dmg);
    }
    void InteractWith(Monster monster){
        std::cout<< name << " says Hi to " << monster.Whoami() << '\n';
    }
    void InteractWith(Player player);
};


int main(){
    Player john("John"), ken("Ken");
    Monster orc("Orc"), goblin("Goblin");

    std::cout<< "---------------------------\n";

    john.InteractWith(ken);
    john.InteractWith(orc);
    john.InteractWith(goblin);

    std::cout<<"---------------------------\n";

    ken.InteractWith(john);
    ken.InteractWith(orc);
    ken.InteractWith(goblin);

    std::cout<<"---------------------------\n";

    orc.InteractWith(john);
    orc.InteractWith(ken);
    orc.InteractWith(goblin);

    std::cout<<"---------------------------\n";

    goblin.InteractWith(john);
    goblin.InteractWith(ken);
    goblin.InteractWith(orc);

	return 0;
}

void Player::InteractWith(Monster monster){
    std::cout<< name << " attacks " << monster.Whoami() << '\n';
}
void Monster::InteractWith(Player player){
    std::cout<< name << " attacks " << player.Whoami() << '\n';
}
