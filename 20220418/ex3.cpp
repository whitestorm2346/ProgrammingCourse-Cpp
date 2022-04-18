#include <iostream>

using namespace std;

class Animal
{
protected:
    int leg;

public:
    Animal() { leg = 4; }
};

class Horse: virtual public Animal
{
};

class Donkey: virtual public Animal
{
};

class Mule: public Horse, public Donkey
{
public:
    void Print() { cout << "Mule has " << leg << " legs" << endl; }
};

int main()
{
    Mule mule;
    mule.Print();
    return 0;
}
