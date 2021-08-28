#include "Student.h"

/*
Kristen is a contender for valedictorian of her high school. 
She wants to know how many students (if any) have scored higher than her in the  exams given during this semester.

The first line contains n, the number of students in Kristen's class. 
The  subsequent lines contain each student's  exam grades for this semester.
How many students got higher mark than her

*/

using namespace std;

int main() {
    int n; // number of students
    cin >> n;
    Student *s = new Student[n]; // an array of n students
    
    for(int i = 0; i < n; i++){
        s[i].input();
    }

    // calculate kristen's score
    int kristen_score = s[0].calculateTotalScore();

    // determine how many students scored higher than kristen
    int count = 0; 
    for(int i = 1; i < n; i++){
        int total = s[i].calculateTotalScore();
        if(total > kristen_score){
            count++;
        }
    }

    // print result
    cout << count;
    
    return 0;
}
