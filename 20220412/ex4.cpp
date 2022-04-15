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

Pump::Pump(): capacity(0),maxCapacity(5){ // �]�w capacity = 0, maxCapacity = 5
  //��X capacity, maxCapacity
  cout<<"capacity: "<<capacity<<endl;
  cout<<"maxCapacity: "<<maxCapacity<<endl;

  while(PumpWater());
  delete this;
}

Pump::Pump(int x): capacity(0),maxCapacity(x){ // �]�w capacity = 0, maxCapacity = x)
  //��X capacity, maxCapacity
  cout<<"capacity: "<<capacity<<endl;
  cout<<"maxCapacity: "<<maxCapacity<<endl;

  while(PumpWater());
  delete this;
}

Pump::Pump(int x, int y): capacity(x),maxCapacity(y){ // �]�w capacity = x, maxCapacity = y
  //��X capacity, maxCapacity
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
  //�إߤ@�ӨS���Ѽ� Pump ����A P1 ���V�Ӫ���
  p1 = new Pump();

  Pump *p2;
  cout<<"Pump p2 start up........"<<endl;
  //�إߤ@�Ӧ��ѼƬ� 3 �� Pump ����A P2 ���V�Ӫ���
  p2 = new Pump(3);

  Pump *p3;
  cout<<"Pump p3 start up........"<<endl;
  //�إߤ@�Ӧ��ѼƬ� 2,4 �� Pump ����A P3 ���V�Ӫ���
  p3 = new Pump(2, 4);

  return 0;
}

/**
��X���G

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
