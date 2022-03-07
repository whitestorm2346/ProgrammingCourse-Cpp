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
    int x;
    int y;
    int targetX;
    int targetY;

public:
    Robot(int tX, int tY, int x = 0, int y = 0)
    {
        setTargetPos(tX, tY);
        setCurrPos(x, y);
        move();
    }
    void setCurrPos(int x, int y){
        this->x = x;
        this->y = y;

        hideCursor();

        gotoxy(x, y);
        std::cout<< '*';
    }
    void setTargetPos(int x, int y){
        this->targetX = x;
        this->targetY = y;
    }
    bool move(){
        if(targetX == x && targetY == y) return true;

        hideCursor();

        if(targetX > x) x++;
        else if(targetX < x) x--;

        if(targetY > y) y++;
        else if(targetY < y) y--;

        gotoxy(x, y);
        std::cout<< '*';

        Sleep(200);

        return move();
    }
};

int main()
{
    int targetX, targetY;

    std::cout<< "input:\n";
    std::cout<< "target location x = ";
    std::cin>> targetX;

    std::cout<< "target location y = ";
    std::cin>> targetY;

    std::cout<< "\nªì©l­È (0,30)\n";

    Robot bot1(targetX, targetY, 0, 30);

    gotoxy(0, 30);

    return 0;
}
