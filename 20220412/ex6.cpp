#include <iostream>
using namespace std;

class Zerg{
// u cannot modify the class Zerg or insert any function onto class Zerg
  private:
    int STR;
    int END;
  public:
    Zerg();
    Zerg(int,int);
    void Print();
    int STRval(){
        return STR;
    }
    int ENDval(){
        return END;
    }
};
Zerg::Zerg():STR(0), END(0){
}
Zerg::Zerg(int s, int e):STR(s), END(e){
}
void Zerg::Print(){
  cout<<"STR="<<STR<<endl;
  cout<<"END="<<END<<endl;
}
class Zergling:public Zerg{
  private:
    int DMG;
    int HP;
    int REG;
  public:
    Zergling(); // set STR=0, END=0, DMG=STR*1.5, HP=END*6, REG=END*0.5
    Zergling(int,int);  // Zergling(int s, int e), set STR=s, END=e, DMG=STR*1.5, HP=END*6, REG=END*0.5
    void Print();  // print out the value of STR, END, DMG, HP, REG
};

Zergling::Zergling(): Zerg(),DMG(STRval()*1.5),HP(ENDval()*6),REG(ENDval()*0.5)
{
    Print();
}
Zergling::Zergling(int s, int e): Zerg(s, e),DMG(STRval()*1.5),HP(ENDval()*6),REG(ENDval()*0.5)
{
    Print();
}
void Zergling::Print()
{
    Zerg::Print();
    cout<<"DMG="<<DMG<<endl;
    cout<<"HP="<<HP<<endl;
    cout<<"REG="<<REG<<endl;
}

class Hydralisk:public Zerg{
  private:
    int DMG;
    int HP;
    int REG;
  public:
    Hydralisk(); // set STR=0, END=0, DMG=STR*2, HP=END*7, REG=END*0.7
    Hydralisk(int,int);  // Hydralisk(int s, int e), set STR=s, END=e, DMG=STR*2, HP=END*7, REG=END*0.7
    void Print();  // print out the value of STR, END, DMG, HP, REG
};

Hydralisk::Hydralisk(): Zerg(),DMG(STRval()*2),HP(ENDval()*7),REG(ENDval()*0.7)
{
    Print();
}
Hydralisk::Hydralisk(int s, int e): Zerg(s, e),DMG(STRval()*2),HP(ENDval()*7),REG(ENDval()*0.7)
{
    Print();
}
void Hydralisk::Print()
{
    Zerg::Print();
    cout<<"DMG="<<DMG<<endl;
    cout<<"HP="<<HP<<endl;
    cout<<"REG="<<REG<<endl;
}

int main(){
  // (1) 輸入 A or B 選擇建立 Zergling or Hydralisk's object, A: Zergling, B: Hydralisk
  //     Input A or B to create a object of Zergling or Hydralisk. A: Zergling, B: Hydralisk
  // (2) 輸入 STR, END, 輸出該 object 的屬性 STR, END, DMG or ENG, HP
  //     Input STR, END, print out the attributes STR, END, DMG or ENG, HP of object

  char input;
  int STR, END;

  cout<<"Input A or B to create a object of Zergling or Hydralisk. A: Zergling, B: Hydralisk\n";
  cin>> input;

  cout<<"Input STR, END, print out the attributes STR, END, DMG or ENG, HP of object\n";
  cin>> STR >> END;

  if(input == 'A' || input == 'a')
  {
      cout<<"Zergling obj:"<<endl;
      Zergling obj(STR, END);
  }
  else if(input == 'B' || input == 'b')
  {
      cout<<"Hydralisk obj:"<<endl;
      Hydralisk obj(STR, END);
  }

  return 0;
}
