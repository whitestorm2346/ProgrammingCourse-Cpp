#include <iostream>

#define SIZE 3

using namespace std;

template <typename Type>
class Stack{
private:
    int top;
    Type data[SIZE];

public:
    Stack(){
        top = -1;
    }
    void Push(Type x){
        cout<<"Push "<<x<<" into stack"<<endl;
        if(top<(SIZE-1))
            data[++top] = x;
        else{
            cout<<"Stack full....."<<endl;
        }
    }
    Type Pop(){
        cout<<"Pop data from stack...."<<endl;
        if(top!=(-1))
            return data[top--];
        else {
            cout<<"Stack empty....."<<endl;

        }
        return -1;
    }
};

int main(){
    Stack<int> intStack;

    intStack.Push(10);
    intStack.Push(20);
    intStack.Push(30);
    intStack.Push(40);
    intStack.Push(50);

    cout<<endl<<"Pop...."<<endl;
    cout<<intStack.Pop()<<endl;
    cout<<intStack.Pop()<<endl;
    cout<<intStack.Pop()<<endl;
    cout<<intStack.Pop()<<endl;
    cout<<intStack.Pop()<<endl;

    return 0;
}
