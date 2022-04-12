#include <iostream>

using namespace std;

class Animal{
  protected:
    int leg;
    int tail;
    int weight;
    char size;
  public:
    Animal()    {
      // complete this constructor, set leg = 4, tail = 1, weight = 3, size = 'S';
      leg = 4;
      tail = 1;
      weight = 3;
      size = 'S';
    }
    Animal(int l, int t, int w)    {
      // complete this constructor, set leg = a, tail = b, weight = w;
      // if weight/50 = 0, set size = 'S'
      // if 0 < weight/50 < 4, size = 'M'
      // if 4<= weight/50 < 7, size = 'L'
      // otherwise size = 'G'
      leg = l;
      tail = t;
      weight = w;

      switch(weight / 50)
      {
          case 0: size = 'S'; break;
          case 1 ... 3: size = 'M'; break;
          case 4 ... 6: size = 'L'; break;
          default: size = 'G';
      }
    }
    void Detail()    {
      // print out leg = ??
      // print out tail = ??
      // print out weight = ?
      // if size = 'S' print out Size = small
      // if size = 'M' print out Size = middle
      // if size = 'L' print out Size = Large
      // if size = 'G' print out Size = Giant
      cout<<"leg: "<<leg<<endl;
      cout<<"tail: "<<tail<<endl;
      cout<<"weight: "<<weight<<endl;

      switch(size)
      {
        case 'S': cout<<"Size = Small\n"; break;
        case 'M': cout<<"Size = Middle\n"; break;
        case 'L': cout<<"Size = Large\n"; break;
        case 'G': cout<<"Size = Giant\n"; break;
      }
    }
};


int main(){
  // you cannot to change any thing in main()
  Animal cat;
  Animal human(2, 0, 80);
  Animal nineTail(6, 9, 1000);

  cout<<"Cat:"<<endl;
  cat.Detail();
  cout<<"Human:"<<endl;
  human.Detail();
  cout<<"Ninetail:"<<endl;
  nineTail.Detail();

  return 0;
}

/**
for example
Animal cat;
cat.Deatil();
The output results must be similar with the following

Leg: 4
Tail: 1
Weight: 3
Size = Small
*/
