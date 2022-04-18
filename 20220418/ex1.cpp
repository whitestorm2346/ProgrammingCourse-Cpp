#include <iostream>

using namespace std;

class Father
{
private:
    int money;

public:
    Father()
    {
        money = 100;
        Print();
    }
    Father(int n)
    {
        money = n;
        Print();
    }
    void Print()
    {
        cout << money << endl;
    }
};

class Child : public Father
{
public:
    Child(int n) : Father(n){}
};

int main()
{
    int n;
    cout << "input money: ";
    cin >> n;

    Child *ken = new Child(n);

    delete ken;

    return 0;
}
