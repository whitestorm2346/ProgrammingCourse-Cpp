#include <iostream>

class Wall
{
    double length;
    double height;

public:
    Wall(double len, double hgt)
    {
        length = len;
        height = hgt;
    }

    double calculateArea()
    {
        return length * height;
    }
};

int main()
{
    Wall wall1(10.5, 8.6), wall2(8.5, 6.3);

    std::cout<< "Area of Wall 1: " << wall1.calculateArea() << '\n';
    std::cout<< "Area of Wall 2: " << wall2.calculateArea() << '\n';

    return 0;
}
