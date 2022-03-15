#include <iostream>
class Student
{
public:
    double marks;

    Student(double marks)
    {
        this->marks = marks;
    }
};

void calAvg(Student s1, Student s2)
{
    std::cout<< "Average Marks = " << (s1.marks + s2.marks) / 2 << '\n';
}

int main()
{
    Student student1(88.0), student2(56.0);

    calAvg(student1, student2);

    return 0;
}
