#include <iostream>

#define SIZE 60

using namespace std;

template <typename Type>
class Message
{
private:
    Type words[SIZE];
    int wordsLength;

public:
    Message();
    void Receive(Type *, int);
    Type* Send(int);
};

template <typename Type>
Message<Type>::Message():wordsLength(0)
{
    words[0] = (Type)NULL;
}

template <typename Type>
void Message<Type>::Receive(Type *msg, int len)
{
    for(int i=0; i<len; i++)
        words[i] = msg[i];

    wordsLength = len;

    cout<<"Receive message: ";

    for(int i=0; i<len; i++)
        cout<<words[i];

    cout<<endl;
    cout<<"Message length = "<<wordsLength<<endl;
}

template <typename Type>
Type * Message<Type>::Send(int len)
{
    len = wordsLength;

    cout<<"Send message: ";

    for(int i=0; i<len; i++)
        cout<<words[i];

    cout<<endl;
    cout<<"Message length = "<<wordsLength<<endl;

    return words;
}

int main()
{
    char charMsg[] = "Hi, I am a student";
    int intMsg[] = {1, 23, 456, 7890, 12};
    Message<char> hello;
    Message<int> number;
    int len;

    hello.Receive(charMsg, 18);
    hello.Send(len);
    number.Receive(intMsg, 5);
    number.Send(len);

    return 0;
}
