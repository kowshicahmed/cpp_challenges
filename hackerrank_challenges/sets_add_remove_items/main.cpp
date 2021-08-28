#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    set<int> numbers;
    int query{};
    int user_data{};
    int no_of_queries{};
    cin >> no_of_queries;
    while (no_of_queries != 0)
    {
        no_of_queries--;
        cin >> query >> user_data;
        switch (query)
        {
        case 1:
        {
            numbers.insert(user_data);
            break;
        }
        case 2:
        {
            std::set<int>::iterator itr1 = numbers.find(user_data);
            if (itr1 != numbers.end())
                numbers.erase(user_data);
            break;
        }
        case 3:
        {
            std::set<int>::iterator itr2 = numbers.find(user_data);
            if (itr2 != numbers.end())
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
            break;
        }
        default:
            break;
        }
    }

    return 0;
}