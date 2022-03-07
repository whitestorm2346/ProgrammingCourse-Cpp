#include <iostream>
#include <windows.h>

void gotoxy(short x, short y){
    COORD pos = {x, y};
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOut, pos);
}
void hideCursor(){
    CONSOLE_CURSOR_INFO cursor_info = {1, 0};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

class Robot{
    char name;
    int x;
    int y;
    int chargingX;
    int chargingY;
    int power;
    int targetX;
    int targetY;

public:
    void setRobotName(char name){
        this->name = name;
    }
    void setCurrPos(int x, int y){
        this->x = x;
        this->y = y;

        hideCursor();

        gotoxy(x, y);
        std::cout<< name;
    }
    void setChargingPos(int x, int y){
        this->chargingX = x;
        this->chargingY = y;
    }
    void setPower(int power){
        this->power = power;
    }
    void setTargetPos(int x, int y){
        this->targetX = x;
        this->targetY = y;
    }
    bool move(){
        if(targetX == x && targetY == y) return false;

        hideCursor();

        gotoxy(x, y);
        std::cout<< ' ';

        if(targetX > x) x++;
        else if(targetX < x) x--;

        if(targetY > y) y++;
        else if(targetY < y) y--;

        gotoxy(x, y);
        std::cout<< name;

        if(power > 0) power -= 5;

        if(power <= 30) setTargetPos(chargingX, chargingY);

        return true;
    }
};

int main()
{
    Robot bot1, bot2;

    bot1.setRobotName('a');
    bot1.setCurrPos(0, 0);
    bot1.setChargingPos(10, 10);
    bot1.setPower(100);
    bot1.setTargetPos(20, 20);

    bot2.setRobotName('b');
    bot2.setCurrPos(50, 30);
    bot2.setChargingPos(10, 10);
    bot2.setPower(40);
    bot2.setTargetPos(15, 15);

    while(bot1.move() | bot2.move()){
        Sleep(200);
    }

    gotoxy(0, 30);

    return 0;
}
