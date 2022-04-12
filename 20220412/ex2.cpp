#include <iostream>
using namespace std;

class Human {
// u cannot modify the class Human or insert any function onto class Human
  private:
    int STR;
    int END;
  public:
    Human();
    Human(int,int);
    void Print();
    int STRval(){
        return STR;
    }
    int ENDval(){
        return END;
    }
};
Human::Human():STR(0), END(0){
}
Human::Human(int s, int e):STR(s), END(e){
}
void Human::Print() {
  cout<<"STR = "<<STR<<endl;
  cout<<"END = "<<END<<endl;
}

class Nurse:public Human{
  private:
    int ENG;
    int HP;
  public:
    Nurse(); // set STR=0, END=0, ENG=STR*100, HP=END*8
    Nurse(int,int);  // Nurse(int s, int e), set STR=s, END=e, ENG=STR*100, HP=END*8
    void Print();  // print out the value of STR, END, ENG, HP
};

Nurse::Nurse():Human(),ENG(STRval()*100),HP(ENDval()*8){
  Print();
}

Nurse::Nurse(int s, int e):Human(s, e),ENG(STRval()*100),HP(ENDval()*8){
  Print();
}

void Nurse::Print(){
  Human::Print();
  cout<<"ENG="<<ENG<<endl;
  cout<<"HP="<<HP<<endl;
}

int main(){
  cout<<"Nurse Marry:"<<endl;
  Nurse Marry;
  cout<<"Nurse Jan:"<<endl;
  Nurse Jan(6, 8);


  return 0;
}
