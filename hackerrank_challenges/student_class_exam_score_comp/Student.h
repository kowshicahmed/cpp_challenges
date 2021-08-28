#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <vector>

class Student
{
private:
    std::vector <int> scores {};
    const int NO_OF_EXAMS = 5;
    
public:
    void input ();
    int calculateTotalScore ();
    
};

#endif // STUDENT_H
