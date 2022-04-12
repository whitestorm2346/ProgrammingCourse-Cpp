#include <iostream>
using namespace std;

class Zerg{
// u cannot modify the class Zerg or insert any function onto class Zerg
  private:
    int STR;
    int END;
    int REG;
  public:
    Zerg();
    Zerg(int,int,int);
    void Print();
    int STRval(){
        return STR;
    }
    int ENDval(){
        return END;
    }
};
Zerg::Zerg():STR(0), END(0), REG(END*0.5){
}
Zerg::Zerg(int s, int e, int r):STR(s), END(e), REG(e*0.5){
}
void Zerg::Print(){
  cout<<"STR="<<STR<<endl;
  cout<<"END="<<END<<endl;
  cout<<"REG="<<STR<<endl;
}

class Zergling:public Zerg{
  private:
    int DMG;
    int HP;
  public:
    Zergling(); // set STR=0, END=0, DMG=STR*1.5, HP=END*6, REG=END*0.5
    Zergling(int,int);  // Zergling(int s, int e), set STR=s, END=e, DMG=STR*1.5, HP=END*6
    void Print();  // print out the value of STR, END, DMG, HP, REG
};

Zergling::Zergling(): Zerg(),DMG(STRval()*1.5),HP(ENDval()*6)
{
    Print();
}
Zergling::Zergling(int s, int e): Zerg(s, e, e*0.5),DMG(STRval()*1.5),HP(ENDval()*6)
{
    Print();
}
void Zergling::Print()
{
    Zerg::Print();
    cout<<"DMG="<<DMG<<endl;
    cout<<"HP="<<HP<<endl;
}

class Hydralisk:public Zerg{
  private:
    int DMG;
    int HP;
  public:
    Hydralisk(); // set STR=0, END=0, DMG=STR*2, HP=END*7, REG=END*0.7
    Hydralisk(int,int);  // Hydralisk(int s, int e), set STR=s, END=e, DMG=STR*2, HP=END*7
    void Print();  // print out the value of STR, END, DMG, HP, REG
};

Hydralisk::Hydralisk(): Zerg(),DMG(STRval()*2),HP(ENDval()*7)
{
    Print();
}
Hydralisk::Hydralisk(int s, int e): Zerg(s, e, e*0.7),DMG(STRval()*2),HP(ENDval()*7)
{
    Print();
}
void Hydralisk::Print()
{
    Zerg::Print();
    cout<<"DMG="<<DMG<<endl;
    cout<<"HP="<<HP<<endl;
}

int main(){
  cout<<"Zergling zug:"<<endl;
  Zergling zgur;
  cout<<"Zergling mud:"<<endl;
  Zergling mud(5, 8);
  cout<<"Hydralisk kaug:"<<endl;
  Hydralisk kaug;
  cout<<"Hydralisk pan:"<<endl;
  Hydralisk pan(10, 5);

  //output should be
  //Zergling zug:
  //STR = xxx
  //END = xxx
  //DMG = xxx
  //HP = xxx


  return 0;
}
