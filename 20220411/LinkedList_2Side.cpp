#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <conio.h>

#define WIDTH 80
#define HEIGHT 40

void gotoxy(short, short);
void hideCursor();

bool endLoop = false;

class Node
{
public:
    clock_t check;
    int time;
    Node* next;
    std::pair<int, int> pos;

    Node(int time = 9);
    ~Node();

    void countDown();
};

class LinkedList
{
    Node* clear(Node* curr);

public:
    Node* front;
    Node* back;

    LinkedList(Node* front = nullptr);
    ~LinkedList();

    void add(Node* newNode);
    void addValue(int delta);
    void countDown();
    void checkZero();
};

class UI
{
public:
    UI(){}
    ~UI(){}

    char pressedKey();
    void action(LinkedList*);
};

int main()
{
    std::srand(std::time(NULL));

    LinkedList* list = new LinkedList();
    UI* ui = new UI();

    while(!endLoop)
    {
        list->countDown();
        ui->action(list);
        list->checkZero();
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
    check = clock();

    pos.first  = rand() % WIDTH;
    pos.second = rand() % HEIGHT;

    hideCursor();
    gotoxy(pos.first, pos.second);

    std::cout<< time;
}
Node::~Node()
{
    hideCursor();
    gotoxy(pos.first, pos.second);

    std::cout<< " ";
}
void Node::countDown()
{
    clock_t curr = clock();

    if((static_cast<double>(curr - check) / CLOCKS_PER_SEC) >= 1)
    {
        hideCursor();
        gotoxy(pos.first, pos.second);

        std::cout<< --time;

        check = clock();
    }
}
LinkedList::LinkedList(Node* front)
{
    this->front = front;
    this->back = front;

    if(front != nullptr) this->back->next = front;
}
LinkedList::~LinkedList()
{
    Node* del = clear(front);

    delete del;
}
void LinkedList::add(Node* newNode)
{
    if(front == nullptr)
    {
        front = back = newNode;
        back->next = front;
    }
    else
    {
        back->next = newNode;
        back = newNode;
        newNode->next = front;
    }
}
void LinkedList::addValue(int delta)
{
    if(front == nullptr) return;

    Node* curr = front;

    do
    {
        curr->time += delta;

        if(curr->time > 9) curr->time = 9;
        else if(curr->time < 0) curr->time = 0;

        hideCursor();
        gotoxy(curr->pos.first, curr->pos.second);

        std::cout<< curr->time;

        curr = curr->next;
    }
    while(curr != front);
}
void LinkedList::countDown()
{
    if(front == nullptr) return;

    Node* curr = front;

    do
    {
        curr->countDown();
        curr = curr->next;
    }
    while(curr != front);
}
void LinkedList::checkZero()
{
    if(front == nullptr) return;
    else if(front == back && front->time == 0)
    {
        delete front;
        front = back = nullptr;
    }
    else
    {
        Node* curr = front;

        for(; curr != back;)
        {
            if(curr->next->time == 0)
            {
                Node* temp = curr->next->next;
                delete curr->next;
                curr->next = temp;
            }
            else curr = curr->next;
        }

        if(front->time == 0)
        {
            front = front->next;
            delete back->next;
            back->next = front;
        }
    }
}
Node* LinkedList::clear(Node* curr)
{
    if(curr->next == front) return curr;

    Node* del = clear(curr->next);

    delete del;

    return curr;
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
        case '+': case '=': list->addValue(1);  break;
        case '-': case '_': list->addValue(-1); break;
        case 'e': case 'E': endLoop = true; gotoxy(0, 0); break;
        default: break;
    }
}
