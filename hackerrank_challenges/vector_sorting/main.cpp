#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main ()
{
    int no_of_elements {};
    int user_input{};
    vector <int> v {};
    cin >> no_of_elements;
    for (int i{}; i < no_of_elements; i++)
    {
        cin >> user_input;
        v.push_back(user_input);
    }
    sort (v.begin(), v.end());

    for (auto out:v)
        cout << out << " ";
    return 0;
}