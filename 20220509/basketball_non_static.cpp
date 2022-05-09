#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <windows.h>

class BasketballPlayer
{
private:
    std::string name;
    int twoPointShotCount;
    int threePointShotCount;
    int scorePoints;

public:
    BasketballPlayer(std::string name);
    virtual ~BasketballPlayer(){}

    int shoot();
    void resetPlayer();
    void printDetail();
};

class BasketballTeam
{
private:
    std::string team;
    std::vector<BasketballPlayer*> players;
    int score;

public:
    BasketballTeam(std::string team);
    virtual ~BasketballTeam();

    int getScore();
    bool check100Points();
    void clear();
    void shoot();
    void resetScore();
    void addPlayer(std::string name);
    void printPlayersDetail();
};

void gotoxy(int x, int y);
void hideCursor();

int main()
{
    srand(time(NULL));

    BasketballTeam rockets("Rockets");
    BasketballTeam lakers("Lakers");

    rockets.addPlayer("Brooks");
    rockets.addPlayer("Wall");

    lakers.addPlayer("James");
    lakers.addPlayer("Morris");

    while(true){
        gotoxy(0, 0);
        hideCursor();

        std::cout<< "Rockets total score points: " << rockets.getScore() << '\n';
        std::cout<< "Lakers total score points: " << lakers.getScore() << "\n\n";

        rockets.printPlayersDetail();
        lakers.printPlayersDetail();

        Sleep(1000);

        if(rand() % 2) rockets.shoot();
        else lakers.shoot();

        if(rockets.check100Points()){
            gotoxy(0, 25);
            hideCursor();

            std::cout<< "Game Over\n";
            std::cout<< "Rockets Wins!\n";

            break;
        }
        else if(lakers.check100Points()){
            gotoxy(0, 25);
            hideCursor();

            std::cout<< "Game Over\n";
            std::cout<< "Lakers Wins!\n";

            break;
        }
    }

    gotoxy(0, 0);
    hideCursor();

    std::cout<< "Rockets total score points: " << rockets.getScore() << '\n';
    std::cout<< "Lakers total score points: " << lakers.getScore() << "\n\n";

    rockets.printPlayersDetail();
    lakers.printPlayersDetail();

    gotoxy(0, 27);

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

BasketballPlayer::BasketballPlayer(std::string name){
    this->name = name;
    twoPointShotCount = 0;
    threePointShotCount = 0;
    scorePoints = 0;
}

int BasketballPlayer::shoot(){
    std::cout<< "                                             \r";
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

void BasketballPlayer::resetPlayer(){
    scorePoints = 0;
    twoPointShotCount = 0;
    threePointShotCount = 0;
}

void BasketballPlayer::printDetail(){
    std::cout<< name << '\n';
    std::cout<< "Two-points shot: " << twoPointShotCount << '\n';
    std::cout<< "Three-points shot: " << threePointShotCount << '\n';
    std::cout<< "Total score points: " << scorePoints << "\n\n";
}

BasketballTeam::BasketballTeam(std::string team){
    this->team = team;
    score = 0;
}

int BasketballTeam::getScore(){
    return score;
}

bool BasketballTeam::check100Points(){
    return (score >= 100);
}

BasketballTeam::~BasketballTeam(){
    clear();
}

void BasketballTeam::clear(){
    while(!players.empty()){
        delete players.back();
        players.pop_back();
    }
}

void BasketballTeam::shoot(){
    score += players[rand() % players.size()]->shoot();
}

void BasketballTeam::resetScore(){
    score = 0;

    for(int i = 0; i < players.size(); i++){
        players[i]->resetPlayer();
    }
}

void BasketballTeam::addPlayer(std::string name){
    players.push_back(new BasketballPlayer(name));
}

void BasketballTeam::printPlayersDetail(){
    for(int i = 0; i < players.size(); i++){
        std::cout<< team << ": ";

        players[i]->printDetail();
    }
}
