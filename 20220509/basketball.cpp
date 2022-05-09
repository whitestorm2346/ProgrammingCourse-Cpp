#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <windows.h>

class BasketballPlayer
{
protected:
    std::string team;
    std::string name;
    int twoPointShotCount;
    int threePointShotCount;
    int scorePoints;

public:
    BasketballPlayer();

    int shoot();
    void printDetails();
};

class Rockets: public BasketballPlayer
{
private:
    static int score;

public:
	Rockets(std::string name);

	void shoot();
	static bool check100Points();
    static int  getScore();
};

class Lakers: public BasketballPlayer
{
private:
    static int score;

public:
	Lakers(std::string name);

	void shoot();
	static bool check100Points();
    static int  getScore();
};

int Rockets::score = 0;
int Lakers::score = 0;

void gotoxy(int x, int y);
void hideCursor();

int main()
{
    srand(time(NULL));

    Rockets brooks("Brooks");
    Rockets wall("Wall");
    Lakers james("James");
    Lakers morris("Morris");

    while(true)
    {
        gotoxy(0, 23);
        hideCursor();

        switch(rand() % 4)
        {
            case 0: brooks.shoot(); break;
            case 1:   wall.shoot(); break;
            case 2:  james.shoot(); break;
            case 3: morris.shoot(); break;
        }

        gotoxy(0, 0);
        hideCursor();

        std::cout<< "Rockets : Lakers\n";
        printf("%7d : %-6d\n\n", Rockets::getScore(), Lakers::getScore());

        gotoxy(0, 3);
        hideCursor();

        brooks.printDetails();
        wall.printDetails();
        james.printDetails();
        morris.printDetails();

        gotoxy(0, 25);
        hideCursor();

        if(Rockets::check100Points())
        {
            std::cout<< "Game Over\n";
            std::cout<< "Rockets Wins!\n";
            break;
        }
        else if(Lakers::check100Points())
        {
            std::cout<< "Game Over\n";
            std::cout<< "Lakers Wins!\n";
            break;
        }

        _sleep(1500);
    }

    return 0;
}

void gotoxy(int x, int y){
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = {x, y};

	SetConsoleCursorPosition(hOut, pos);
}

void hideCursor(){
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;

	GetConsoleCursorInfo(hOut, &cursorInfo);

	cursorInfo.bVisible = false;

	SetConsoleCursorInfo(hOut, &cursorInfo);
}

BasketballPlayer::BasketballPlayer(){
    twoPointShotCount = 0;
    threePointShotCount = 0;
    scorePoints = 0;
}

int BasketballPlayer::shoot(){
    std::cout<< "                                                      \r";
    std::cout<< ">>> ";

    switch(rand() % 4){
        case 1: case 2:
            std::cout<< name << " score two points\n";
            twoPointShotCount++;
            scorePoints += 2;
            return 2;

        case 3:
            std::cout<< name << " score three points\n";
            threePointShotCount++;
            scorePoints += 3;
            return 3;

        default:
            std::cout<< name << " missed the shot\n";
            return 0;
    }
}

void BasketballPlayer::printDetails(){
    std::cout<< team << ": " << name << '\n';
    std::cout<< "Two-points shot: " << twoPointShotCount << '\n';
    std::cout<< "Three-points shot: " << threePointShotCount << '\n';
    std::cout<< "Total score points: " << scorePoints << "\n\n";
}

Rockets::Rockets(std::string name){
    this->team = "Rockets";
    this->name = name;
}

void Rockets::shoot(){
    score += BasketballPlayer::shoot();
}
bool Rockets::check100Points(){
    return (score >= 100);
}
int Rockets::getScore(){
    return score;
}

Lakers::Lakers(std::string name){
    this->team = "Lakers";
    this->name = name;
}

void Lakers::shoot(){
    score += BasketballPlayer::shoot();
}
bool Lakers::check100Points(){
    return (score >= 100);
}
int Lakers::getScore(){
    return score;
}
