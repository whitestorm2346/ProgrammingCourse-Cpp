#include <iostream>
#include <string.h>

using namespace std;

class Human{
public:
    Human(){}
    virtual ~Human(){}

    virtual void Intro(char *n) = 0;
};

class Teacher: public Human
{
private:
    char name[20];

public:
    void Intro(char *n)
    {
      strcpy(name, n);
      cout<<"Hello, my name is "<<name<<endl;
      cout<<"My career is a teacher, I teach C++ programming language!"<<endl;
    }
};

class Student: public Human
{
private:
    char name[20];

public:
    void Intro(char *n)
    {
      strcpy(name, n);
      cout<<"Hello, my name is "<<name<<endl;
      cout<<"I am a student, I studied at the Department of Information Engineering, Tamkang University"<<endl;
    }
};

void Interview(Human *, char *);
void Interview(Human *p, char *name)
{
    p->Intro(name);
}

int main()
{
    Teacher John;
    Student Cherry;

    Interview(&John,"John");
    Interview(&Cherry,"Cherry");

    return 0;
}

/**

Using pure-virtual function, let the codes of void Interview() and int main() should be as following,

void Interview(Human *, char *);
void Interview(Human *p, char *name)
{
  p->Intro(name);
}

int main()
{
  Teacher John;
  Student Cherry;

  Interview(&John,"John");
  Interview(&Cherry,"Cherry");

  return 0;
}

*/
