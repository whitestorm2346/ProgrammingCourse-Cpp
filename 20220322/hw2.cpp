#include <iostream>
#include <string>

using namespace std;

class Player;
class Monster;

class Object{
    protected:
        string name;
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
	    Object(string n, int x){
	        name = n;
            dmg = x;
	    }
		void Action(){
			cout<<"Do nothing......"<<endl;
		}
		void MoveTo(int x, int y){
            cout<<"Walking to location("<<x<<","<<y<<")"<<endl;
		}
		void Attack(int dmg){
            cout<<"Attack......."<<endl;
            cout<<"Damage: "<<dmg<<endl;
		}
		string Whoami(){
            return name;
		}

		void InteractWith(Object obj){
		    cout<<name<<" interact with "<<obj.Whoami()<<endl;
		}
};

class Player: public Object{
    private:
        int magicDmg;
    public:
        Player():Object("Player",10){
            magicDmg = 10;
            //cout<<"dmg = "<<dmg<<endl;
            //cout<<"magicDmg = "<<magicDmg<<endl;
        }
        Player(string myName):Object(myName,10){
            magicDmg = 10;
            //cout<<"dmg = "<<dmg<<endl;
            //cout<<"magicDmg = "<<magicDmg<<endl;
        }
    	void Action(){
			MoveTo(10,20);
			Attack();
		}
		void Attack(){
            cout<<"Casting magic......"<<endl;
            Object::Attack(dmg+magicDmg);
		}
		void InteractWith(Player player){
		    cout<<name<<" says Hi to "<<player.Whoami()<<endl;
		}
		void InteractWith(Monster monster);
};

class Monster: public Object{
    public:
        Monster():Object("Monster",20){
            //cout<<"dmg = "<<dmg<<endl;
        }
        Monster(string myName):Object(myName,20){
            //cout<<"dmg = "<<dmg<<endl;
        }
    	void MoveTo(int x, int y){
            cout<<"Flying to location("<<x<<","<<y<<")"<<endl;
		}
		void Action(){
			MoveTo(10,20);
			Attack(dmg);
		}
		void InteractWith(Monster monster){
		    cout<<name<<" says Hi to "<<monster.Whoami()<<endl;
		}
		void InteractWith(Player player);
};


int main(){
    Player john("John"), ken("Ken");
    Monster orc("Orc"), goblin("Goblin");
    cout<<"---------------------------"<<endl;
    john.InteractWith(ken);
    john.InteractWith(orc);
    john.InteractWith(goblin);
    cout<<"---------------------------"<<endl;
    ken.InteractWith(john);
    ken.InteractWith(orc);
    ken.InteractWith(goblin);
    cout<<"---------------------------"<<endl;
    orc.InteractWith(john);
    orc.InteractWith(ken);
    orc.InteractWith(goblin);
    cout<<"---------------------------"<<endl;
    goblin.InteractWith(john);
    goblin.InteractWith(ken);
    goblin.InteractWith(orc);

	return 0;
}

void Player::InteractWith(Monster monster){
    cout<<name<<" attacks "<<monster.Whoami()<<endl;
}
void Monster::InteractWith(Player player){
    cout<<name<<" attacks "<<player.Whoami()<<endl;
}
