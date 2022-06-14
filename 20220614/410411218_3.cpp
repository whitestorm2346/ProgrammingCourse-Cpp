#include <iostream>

using namespace std;

class Car{
private:
    int seat;
    int airBag;

public:
    Car(): seat(4), airBag(4){}
    Car(int s): seat(s), airBag(s){}
    Car(int s, int a): seat(s), airBag(a){}

    void Equipment(){
        cout<< "Seat:" << seat << '\n';
        cout<< "Air Bag:" << airBag << '\n';
    }
};

class RubbishTruck: public Car{
private:
    int trashBox;

public:
    RubbishTruck(): Car(2), trashBox(1){}
    RubbishTruck(int t): Car(2), trashBox(t){}
    RubbishTruck(int s, int a, int t): Car(s, a), trashBox(t){}

    void Equipment(){
        Car::Equipment();
        cout<< "Trash Box:" << trashBox << '\n';
    }
};

int main(){
    Car moonStar, darkNight(5), sunRain(7,4);
    RubbishTruck toyo, yama(4), kime(4,2,6);

    cout<<"Equipment of Car MoonStar:"<<endl;
    moonStar.Equipment();
    cout<<"Equipment of Car darkNight(5):"<<endl;
    darkNight.Equipment();
    cout<<"Equipment of Car SunRain(7,4):"<<endl;
    sunRain.Equipment();
    cout<<"Equipment of RubbishTruck toyo:"<<endl;
    toyo.Equipment();
    cout<<"Equipment of RubbishTruck yama(4):"<<endl;
    yama.Equipment();
    cout<<"Equipment of RubbishTruck kime(4,2,6):"<<endl;
    kime.Equipment();

    return 0;
}
