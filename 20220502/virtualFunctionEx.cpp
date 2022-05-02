#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Animal{
public:
    virtual void Sound() = 0;
};

class Cat: public Animal{
private:
    string name;
public:
    Cat(string n){
        name = n;
    }
    void Sound(){
        cout<<"Now "<<name<<" is speaking: ";
        cout<<"Meow......"<<endl;
    }
};

class Duck: public Animal{
private:
    string name;
public:
    Duck(string n){
        name = n;
    }
    void Sound(){
        cout<<"Now "<<name<<" is speaking: ";
        cout<<"Quack......"<<endl;
    }
};

class Dog: public Animal{
private:
    string name;
public:
    Dog(string n){
        name = n;
    }
    void Sound(){
        cout<<"Now "<<name<<" is speaking: ";
        cout<<"Woof......"<<endl;
    }
};

void NowSpeak(Animal &animal){
    animal.Sound();
    _sleep(1000);
}

int main(){
    Cat kitty("Kitty");
    Duck donald("Donald");
    Dog goofy("Goofy");

	for(;;){
	    NowSpeak(kitty);
	    NowSpeak(donald);
	    NowSpeak(goofy);	
	} 

    return 0;
}
