#include <iostream>

using namespace std;

class Father
{
private:
    int money;

public:
    Father() { money = 200; }
    void Print()
    {
        cout << "money = " << money << endl;
    }
    int MyMoney() { return money; }
};

class Child : public Father
{
private:
    int book;

public:
    void Print()
    {
        int price;
        cout << "price:";
        cin >> price;
        book = MyMoney() / price;
        Father::Print();
        cout << "book = " << book << endl;
    }
};

int main()
{
    Child john;
    john.Print();
    return 0;
}
