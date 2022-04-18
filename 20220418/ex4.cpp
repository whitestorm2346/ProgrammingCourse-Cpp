#include <iostream>

using namespace std;

class Clock
{
private:
    int hour;
    int minute;
    int second;

public:
    void SetTime(int h, int m, int s)
    {
        hour = h;
        minute = m;
        second = s;
    }
    void WhatTime()
    {
        cout<< hour << " : " << minute << " : " << second << endl;
    }
};
int main()
{
    Clock* myClock;
    int hour, minute, second;
    cout << "time = ";
    cin >> hour >> minute >> second;

    myClock = new Clock;

    myClock->SetTime(hour, minute, second);
    myClock->WhatTime();

    return 0;
}
