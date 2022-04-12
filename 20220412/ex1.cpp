#include <iostream>

using namespace std;

class Elf
{
private:
    int HP;
    int AC;
    int STR;
    int ATK;
    int DEF;
    char eyeColor;

public:
    Elf()
    {
      HP = 100, AC = 5, STR = 10;
      ATK = STR/10, DEF = AC/5;
      eyeColor = 'G';
    }
    Elf(int h, int a, int s, char c)
    {
      HP = h, AC = a, STR = s, eyeColor = c;
      ATK = STR/10, DEF = AC/5;
    }

    void Detail(){
      cout<< "HP = " << HP << '\n';
      cout<< "AC = " << AC << '\n';
      cout<< "STR = " << STR << '\n';
      cout<< "ATK = " << ATK << '\n';
      cout<< "DEF = " << DEF << '\n';

      switch(eyeColor)
      {
          case 'G': case 'g': cout<< "Eye color is Green\n";  break;
          case 'P': case 'p': cout<< "Eye color is Purple\n"; break;
      }
    }
};

int main(){
  // you cannot to change any thing in main()

  Elf alpha;
  Elf beta(120, 2, 5, 'p');
  Elf gamma(80, 10, 25, 'G');

  cout<<"alpha:"<<endl;
  alpha.Detail();
  cout<<"beta:"<<endl;
  beta.Detail();
  cout<<"gamma:"<<endl;
  gamma.Detail();

  return 0;
}

/**
for example,

Elf alpha;
alpha.Detail();
The output results must be similar with the following

HP = 100
AC = 5
STR = 10
ATK = 1
DEF = 1
Eye color is Green

*/
