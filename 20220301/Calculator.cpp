#include <iostream>
#include <conio.h>

class Calculator
{
    int num1;
    int num2;
    char _operator;

public:
    void eval()
    {
        char input;

        do
        {
            input = getch();
        }
        while(!(input >= '0' && input <= '9'));

        num1 = input - '0';
        std::cout<< input;

        for(bool rerun = true; rerun;)
        {
            _operator = getch();

            switch(_operator)
            {
                case '+': case '-': case '*': case '/': case '%':
                    rerun = false;
                    std::cout<< _operator;
                    break;

                default: rerun = true;
            }
        }

        do
        {
            input = getch();
        }
        while(!(input >= '0' && input <= '9'));

        num2 = input - '0';
        std::cout<< input;

        input = getch();
        std::cout<< input;

        if(input == '=') std::cout<< calculate() << '\n';
        else std::cout<< " ERROR\n";
    }
    int calculate()
    {
        switch(_operator)
        {
            case '+': return num1 + num2; break;
            case '-': return num1 - num2; break;
            case '*': return num1 * num2; break;
            case '/': return num1 / num2; break;
            case '%': return num1 % num2; break;
            default: return 0;
        }
    }

};

int main()
{
    Calculator* calculator = new Calculator;

    for(;;)
    {
        calculator->eval();
    }

    delete calculator;

    return 0;
}
