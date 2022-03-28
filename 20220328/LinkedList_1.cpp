#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <conio.h>

#define WIDTH 80
#define HEIGHT 40

class Node
{
public:
    int time;
    Node* next;
    std::pair<int, int> pos;

    Node(int time = 9);
    ~Node(){}
};

class LinkedList
{
public:
    Node* front;
    Node* back;

    LinkedList(Node* front = nullptr);
    ~LinkedList();

    void add(Node* newNode);
};

class UI
{
public:
    UI(){}
    ~UI(){}

    char pressedKey();
    void action(LinkedList*);
};

void gotoxy(short, short);
void hideCursor();

int main()
{
    std::srand(std::time(NULL));

    LinkedList* list = new LinkedList();
    UI* ui = new UI();

    while(true)
    {
        ui->action(list);
    }

    delete list;
    delete ui;

    return 0;
}

void gotoxy(short x, short y)
{
    COORD pos = {x, y};
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOut, pos);
}
void hideCursor()
{
    CONSOLE_CURSOR_INFO cursor_info = {1, 0};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

Node::Node(int time)
{
    this->time = time;
    next = nullptr;

    pos.first  = rand() % WIDTH;
    pos.second = rand() % HEIGHT;

    hideCursor();
    gotoxy(pos.first, pos.second);

    std::cout<< time;
}
LinkedList::LinkedList(Node* front)
{
    this->front = this->back = front;

    if(front != nullptr) this->back->next = front;
}
LinkedList::~LinkedList()
{

}
void LinkedList::add(Node* newNode)
{
    if(front == nullptr) front = back = newNode;
    else
    {
        back->next = newNode;
        newNode->next = front;
        back = newNode;
    }
}
char UI::pressedKey()
{
    if(kbhit()) return static_cast<char>(getch());
    else return static_cast<char>(NULL);
}
void UI::action(LinkedList* list)
{
    switch(pressedKey())
    {
        case 'a': case 'A': list->add(new Node()); break;
        default: break;
    }
}
