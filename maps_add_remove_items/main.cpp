#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <istream>

using namespace std;

int main()
{
    map<string, int> students;
    int query{};
    int score{};
    string student_name {};
    int no_of_queries{};
    cin >> no_of_queries;
    while (no_of_queries != 0)
    {
        no_of_queries--;
        cin >> query;
        switch (query)
        {
        case 1:
        {
            cin >> student_name >> score;
            std::map<string, int>::iterator itr3 = students.find(student_name);
            if (itr3 == students.end())
                students.insert(make_pair(student_name, score));
            else
                itr3->second+= score;
            break;
        }
        case 2:
        {
            cin >> student_name;
            std::map<string, int>::iterator itr1 = students.find(student_name);
            if (itr1 != students.end())
                itr1->second = 0;
            break;
        }
        case 3:
        {
            cin >> student_name;
            std::map<string, int>::iterator itr2 = students.find(student_name);
            if (itr2 != students.end())
                cout << students[student_name] << endl;
            else
                cout << 0 << endl;
            break;
        }
        default:
            break;
        }
    }

    return 0;
}