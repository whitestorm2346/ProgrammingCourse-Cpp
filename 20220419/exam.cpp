#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>

// part 10-1
#define WIDTH 40
#define HEIGHT 15

// extra
#define IDLE 0
#define RUN_OUT_POWER 1
#define RUN_OUT_CAPACITY 2

#define iabs(n) ((n < 0) ? (-n) : n)

class Node;
class LinkedList;
class Robot;
class SweeperRobot;

// extra
class Node
{
public:
    int x;
    int y;
    Node* prev;
    Node* next;

    Node(int x, int y);
};

class LinkedList
{
public:
    Node* front;
    Node* back;

    LinkedList();
    ~LinkedList();

    // part 10-2
    void show();
    void add(SweeperRobot* robot, Node* newNode);
    void Status();
    // part 10-2 end

    bool cleanTrash(int x, int y);
};
// extra end

class Robot
{
private:
    // part 1
    int x;
    int y;
    int chargingX;
    int chargingY;
    int power;
    int maxPower;
    int targetX;
    int targetY;
    // part 1 end

public:
    Robot(); // part 2.1
    Robot(int a, int b); // part 2.2

    // part 2.3
    void SetLocation(int x, int y);
    void SetChargingLocation(int chargingX, int chargingY);
    void SetPower(int power);
    void SetMaxPower(int maxPower);
    void SetTargetLocation(int targetX, int targetY);
    void Status();
    // part 2.3 end

    // extra
    std::pair<int, int> getCurrLocation();
    std::pair<int, int> getChargingSpotLocation();
    void gotoChargingSpot(int type);
    void charge(); // part 10-4-b
    int getPowerValue();
    float getPower();
    bool isOnChargingSpot();
    bool moving();
    void move();
    void showRobot();
    void showChargingSpot();

protected:
    bool toChargingSpot;
    int type;
    // extra end
};

// part 7
class SweeperRobot: public Robot
{
private:
    int capacity;
    int maxCapacity;
    // part 7 end

public:
    SweeperRobot(); // part 8.1
    SweeperRobot(int a, int b, int ca, int cb, int n); // part 8.2

    // part 8.3
    void SetCapacity(int capacity);
    void SetMaxCapacity(int maxCapacity);
    void SetTargetLocation(int targetX, int targetY);
    void Status();
    // part 8.3 end

    // extra
    float getCapacity();
    void cleanCapacity(); // part 10-4-a
    void move(LinkedList* trash);
    // extra end
};

int countDistance(SweeperRobot* robot, Node* trash);
void print(int x, int y, char chr);
void hideCursor();
void gotoxy(int x, int y);

int main()
{
/**
    // part 3.1
    Robot* robot1 = new Robot();
    robot1->SetTargetLocation(25, 20);
    delete robot1;
    // part 3.1 end

    // part 3.2
    Robot* robot2 = new Robot(20, 20);
    robot2->SetTargetLocation(40, 10);
    delete robot2;
    // part 3.2 end

    // part 4
    Robot* robot1 = new Robot();
    Robot* robot2 = new Robot();

    robot1->SetLocation(0, 0);
    robot1->SetChargingLocation(10, 10);
    robot1->SetPower(150);
    robot1->SetMaxPower(150);
    robot1->SetTargetLocation(20, 20);

    robot2->SetLocation(50, 30);
    robot2->SetChargingLocation(10, 10);
    robot2->SetPower(20);
    robot2->SetMaxPower(100);
    robot2->SetTargetLocation(15, 15);
    // part 4 end

    // part 5
    while(robot1->move() | robot2->move())
    {
        Sleep(200);
    }
    // part 5 end

    delete robot1;
    delete robot2;
*/
    srand(time(NULL));

    // part 10-3
    SweeperRobot* robot = new SweeperRobot(0, 14, 0, 14, 100);

    robot->SetPower(150);
    robot->SetMaxPower(150);
    // part 10-3 end

    LinkedList* trash = new LinkedList();
    clock_t check = clock();

    while(true)
    {
        // part 10-2
        if((clock() - check) / CLOCKS_PER_SEC >= 1)
        {
            trash->add(robot, new Node(rand() % WIDTH, rand() % HEIGHT));

            check = clock();
        }

        robot->move(trash);
        trash->show();
        // part 10-2 end

        robot->showChargingSpot();
        robot->showRobot();

        // part 10-5
        gotoxy(0, 16);
        robot->Status();
        trash->Status();
        // part 10-5 end

        Sleep(50);
    }

    delete robot;
    delete trash;

    return 0;
}

int countDistance(SweeperRobot* robot, Node* trash)
{
    return iabs(robot->getChargingSpotLocation().first - trash->x) +
           iabs(robot->getChargingSpotLocation().second - trash->y);
}
void print(int x, int y, char chr)
{
    hideCursor();
    gotoxy(x, y);
    std::cout<< chr;
}
void hideCursor()
{
    CONSOLE_CURSOR_INFO cursor_info = {1, 0};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
void gotoxy(int x, int y)
{
    COORD pos = {static_cast<short>(x), static_cast<short>(y)};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

// extra
Node::Node(int x, int y)
{
    this->x = x;
    this->y = y;
    prev = nullptr;
    next = nullptr;
}

LinkedList::LinkedList()
{
    front = nullptr;
    back = nullptr;
}
LinkedList::~LinkedList()
{

}

// part 10-2
void LinkedList::show()
{
    for(Node* curr = front; curr != nullptr; curr = curr->next)
    {
        print(curr->x, curr->y, '@');
    }
}
void LinkedList::Status()
{
    if(front == nullptr) std::cout<< "front NULL\n";
    else std::cout<< "front (" << front->x << ", " << front->y << ")\n";
}
void LinkedList::add(SweeperRobot* robot, Node* newNode)
{
    if(front == nullptr)
    {
        front = newNode;
        back = newNode;
    }
    else
    {
        if(countDistance(robot, newNode) >= countDistance(robot, front))
        {
            front->prev = newNode;
            newNode->next = front;
            front = newNode;
        }
        else if(countDistance(robot, newNode) < countDistance(robot, back))
        {
            back->next = newNode;
            newNode->prev = back;
            back = newNode;
        }
        else
        {
            for(Node* curr = front; curr != back; curr = curr->next)
            {
                if(countDistance(robot, newNode) < countDistance(robot, curr) &&
                   countDistance(robot, newNode) >= countDistance(robot, curr->next))
                {
                    curr->next->prev = newNode;
                    newNode->next = curr->next;
                    curr->next = newNode;
                    newNode->prev = curr;
                    break;
                }
            }
        }
    }
}
// part 10-2 end

bool LinkedList::cleanTrash(int x, int y)
{
    Node* curr = front;

    if(front != nullptr)
    {
        if(front == back && (curr->x == x && curr->y == y))
        {
            delete front;
            front = nullptr;
            back = nullptr;

            return true;
        }
        else
        {
            while(curr != nullptr)
            {
                if(curr->x == x && curr->y == y)
                {
                    if(curr == front)
                    {
                        front = front->next;
                        delete front->prev;
                        front->prev = nullptr;
                    }
                    else if(curr == back)
                    {
                        back = back->prev;
                        delete back->next;
                        back->next = nullptr;
                    }
                    else
                    {
                        curr->prev->next = curr->next;
                        curr->next->prev = curr->prev;
                        delete curr;
                    }

                    return true;
                }
                else curr = curr->next;
            }
        }
    }

    return false;
}
// extra end

Robot::Robot() // part 2.1
{
    x = 0;
    y = 0;
    chargingX = 0;
    chargingY = 0;
    power = 100;
    maxPower = 100;
    targetX = 0;
    targetY = 0;

    // extra
    toChargingSpot = false;
    type = 0;
}
Robot::Robot(int a, int b) // part 2.2
{
    x = a;
    y = b;
    chargingX = 0;
    chargingY = 0;
    power = 100;
    maxPower = 100;
    targetX = a;
    targetY = b;

    // extra
    toChargingSpot = false;
    type = 0;
}

// part 2.3
void Robot::SetLocation(int x, int y)
{
    this->x = x;
    this->y = y;
}
void Robot::SetChargingLocation(int chargingX, int chargingY)
{
    this->chargingX = chargingX;
    this->chargingY = chargingY;
}
void Robot::SetPower(int power)
{
    this->power = power;
}
void Robot::SetMaxPower(int maxPower)
{
    this->maxPower = maxPower;
}
void Robot::SetTargetLocation(int targetX, int targetY)
{
    this->targetX = targetX;
    this->targetY = targetY;
}
void Robot::Status()
{
    std::cout<< "Location = (" << x << ", " << y << ")\n";
    std::cout<< "Charging Location = (" << chargingX << ", " << chargingY << ")\n";
    std::cout<< "Power = ";
    printf("%5.1f%%\n", getPower());
    std::cout<< "Target Location = (" << targetX << ", " << targetY << ")\n";
}
// part 2.3 end

// extra
std::pair<int, int> Robot::getCurrLocation()
{
    return {x, y};
}
std::pair<int, int> Robot::getChargingSpotLocation()
{
    return {chargingX, chargingY};
}
void Robot::gotoChargingSpot(int type)
{
    this->type = type;
    toChargingSpot = (type != IDLE);
    SetTargetLocation(chargingX, chargingY);
}
void Robot::charge() // part 10-4-b
{
    if(power < maxPower)
    {
        power += 10;

        if(power > maxPower) power = maxPower;
    }
    else
    {
        type = IDLE;
        toChargingSpot = false;
    }
}
int Robot::getPowerValue()
{
    return power;
}
float Robot::getPower()
{
    return static_cast<float>(power) / maxPower * 100;
}
bool Robot::isOnChargingSpot()
{
    return (x == chargingX && y == chargingY);
}
bool Robot::moving()
{
    if(targetX == x && targetY == y) return false;

    print(x, y, ' ');

    if(targetX > x) x++;
    else if(targetX < x) x--;

    if(targetY > y) y++;
    else if(targetY < y) y--;

    print(x, y, 'R');

    return true;
}
void Robot::move()
{
    if(!moving()) return;

    // part 6
    if(!toChargingSpot) power -= 5;

    if(getPower() < 10) gotoChargingSpot(RUN_OUT_POWER);
    // part 6 end
}
void Robot::showRobot()
{
    print(x, y, 'R');
}
void Robot::showChargingSpot()
{
    print(chargingX, chargingY, 'C');
}
// extra end

SweeperRobot::SweeperRobot() // part 8.1
{
    capacity = 0;
    maxCapacity = 100;
}
SweeperRobot::SweeperRobot(int a, int b, int ca, int cb, int n): Robot(a, b) // part 8.2
{
    capacity = 0;
    maxCapacity = n;

    SetChargingLocation(ca, cb);
}

// part 8.3
void SweeperRobot::SetCapacity(int capacity)
{
    this->capacity = capacity;
}
void SweeperRobot::SetMaxCapacity(int maxCapacity)
{
    this->maxCapacity = maxCapacity;
}
void SweeperRobot::SetTargetLocation(int targetX, int targetY)
{
    Robot::SetTargetLocation(targetX, targetY);
}
void SweeperRobot::Status()
{
    Robot::Status();

    std::cout<< "Capacity = ";
    printf("%5.1f%%\n", getCapacity());
}
// part 8.3 end

// extra
float SweeperRobot::getCapacity()
{
    return (1 - static_cast<float>(capacity) / maxCapacity) * 100;
}
void SweeperRobot::cleanCapacity() // part 10-4-a
{
    if(capacity > 0)
    {
        capacity -= 10;

        if(capacity < 0) capacity = 0;
    }
    else
    {
        type = IDLE;
        toChargingSpot = false;
        gotoChargingSpot(IDLE);
    }
}
void SweeperRobot::move(LinkedList* trash)
{
    if(!moving())
    {
        if(isOnChargingSpot())
        {
            switch(type)
            {
                case RUN_OUT_POWER:
                    charge();
                    break;

                case RUN_OUT_CAPACITY:
                    cleanCapacity();
                    break;

                case IDLE:
                    if(trash->front != nullptr) SetTargetLocation(trash->front->x, trash->front->y);
            }
        }
        else if(trash->front != nullptr) SetTargetLocation(trash->front->x, trash->front->y);
        else return;
    }

    // part 9
    if(!toChargingSpot)
    {
        SetPower(getPowerValue() - 5);

        if(trash->cleanTrash(getCurrLocation().first, getCurrLocation().second)) capacity += 5;
    }

    if(getPower() < 10) gotoChargingSpot(RUN_OUT_POWER);
    else if(getCapacity() < 5) gotoChargingSpot(RUN_OUT_CAPACITY);
    // part 9 end
}
// extra end
