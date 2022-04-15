#include <iostream>
using namespace std;

class Pump{
private:
  int capacity;
  int maxCapacity;
public:
  Pump();
  Pump(int);
  Pump(int, int);
 ~Pump();
  int PumpWater();
};

Pump::Pump(): capacity(0),maxCapacity(5){ // 設定 capacity = 0, maxCapacity = 5
  //輸出 capacity, maxCapacity
  cout<<"capacity: "<<capacity<<endl;
  cout<<"maxCapacity: "<<maxCapacity<<endl;

  while(PumpWater());
  delete this;
}

Pump::Pump(int x): capacity(0),maxCapacity(x){ // 設定 capacity = 0, maxCapacity = x)
  //輸出 capacity, maxCapacity
  cout<<"capacity: "<<capacity<<endl;
  cout<<"maxCapacity: "<<maxCapacity<<endl;

  while(PumpWater());
  delete this;
}

Pump::Pump(int x, int y): capacity(x),maxCapacity(y){ // 設定 capacity = x, maxCapacity = y
  //輸出 capacity, maxCapacity
  cout<<"capacity: "<<capacity<<endl;
  cout<<"maxCapacity: "<<maxCapacity<<endl;

  while(PumpWater());
  delete this;
}

Pump::~Pump(){
  cout<<"capacity: "<<capacity<<endl;
  cout<<"Pump full........................."<<endl;
}

int Pump::PumpWater(){
  if(++capacity>=maxCapacity)
    return 0;
  cout<<"capacity: "<<capacity<<endl;
  return 1;
}

int main(){
  Pump *p1;
  cout<<"Pump p1 start up........"<<endl;
  //建立一個沒有參數 Pump 物件， P1 指向該物件
  p1 = new Pump();

  Pump *p2;
  cout<<"Pump p2 start up........"<<endl;
  //建立一個有參數為 3 的 Pump 物件， P2 指向該物件
  p2 = new Pump(3);

  Pump *p3;
  cout<<"Pump p3 start up........"<<endl;
  //建立一個有參數為 2,4 的 Pump 物件， P3 指向該物件
  p3 = new Pump(2, 4);

  return 0;
}

/**
輸出結果

Pump p1 start up........
capacity: 0
maxCapacity: 5
capacity: 1
capacity: 2
capacity: 3
capacity: 4
capacity: 5
Pump full.........................
Pump p2 start up........
capacity: 0
maxCapacity: 3
capacity: 1
capacity: 2
capacity: 3
Pump full.........................
Pump p3 start up........
capacity: 2
maxCapacity: 4
capacity: 3
capacity: 4
Pump full.........................
*/
