#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 15

class Robot
{
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
    void print(int x, int y, char chr);
    float getPower();
    bool move();
    // extra end
};

// part 7
class SweeperRobot: public Robot
{
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
    bool move();
    // extra end
};

void gotoxy(short x, short y);
void hideCursor();

int main()
{
/**
    // part 3.1
    Robot* robot1 = new Robot();
    robot1->SetTargetLocation(25, 20);
    delete robot1;

    // part 3.2
    Robot* robot2 = new Robot(20, 20);
    robot2->SetTargetLocation(40, 10);
    delete robot2;

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

Robot::Robot() // part 2.1
{
    x = y = 0;
    chargingX = chargingY = 0;
    power = maxPower = 100;
    targetX = targetY = 0;
}
Robot::Robot(int a, int b) // part 2.2
{
    x = a;
    y = b;
    chargingX = chargingY = 0;
    power = maxPower = 100;
    targetX = targetY = 0;
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
    std::cout<< "Location = (" << x << "," << y << ")\n";
    std::cout<< "Charging Location = (" << x << "," << y << ")\n";
    std::cout<< "Power = ";
    printf("%.1f%%\n", getPower());
    std::cout<< "Target Location = (" << targetX << "," << targetY << ")\n";

    print(chargingX, chargingY, 'C');
    print(chargingX, chargingY, 'R');
}
// part 2.3 end

// extra
void Robot::print(int x, int y, char chr)
{
    hideCursor();
    gotoxy(x, y);
    std::cout<< chr;
}
float Robot::getPower()
{
    return static_cast<float>(power) / maxPower * 100;
}
bool Robot::move()
{
    if(targetX == x && targetY == y) return false;

    print(x, y, ' ');

    if(targetX > x) x++;
    else if(targetX < x) x--;

    if(targetY > y) y++;
    else if(targetY < y) y--;

    print(x, y, 'R');

    // part 6
    if(power > 0) power -= 5;

    if(getPower() <= 10.f) SetTargetLocation(chargingX, chargingY);
    // part 6 end

    return true;
}
// extra end

SweeperRobot::SweeperRobot(): Robot() // part 8.1
{
    capacity = 0;
    maxCapacity = 100;
}
SweeperRobot::SweeperRobot(int a, int b, int ca, int cb, int n) // part 8.2
{
    capacity = 0;
    maxCapacity = n;

    SetLocation(a, b);
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
    printf("%.1f%%\n", getCapacity());
}
// part 8.3 end

// extra
float SweeperRobot::getCapacity()
{
    return (1 - static_cast<float>(capacity) / maxCapacity) * 100;
}
bool SweeperRobot::move()
{

}
// extra end
