#include "Student.h"

void Student::input ()
    {
        int user_data {};
        for (int i {}; i < NO_OF_EXAMS; i++)
        {
            std::cin >> user_data;
            scores.push_back (user_data);
        }
    }
    
int Student::calculateTotalScore ()
    {
        int sum {};
        for (auto score: scores)
            sum += score;
        return sum;
    }

