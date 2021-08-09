#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main ()
{
    int no_of_elements {};
    int user_input{};
    int del_element_at_pos{};
    int del_element_range_1 {};
    int del_element_range_2 {};

    vector <int> v {};

    cin >> no_of_elements;

    for (int i{}; i < no_of_elements; i++)
    {
        cin >> user_input;
        v.push_back(user_input);
    }
    cin >> del_element_at_pos;
    v.erase (v.begin () + (del_element_at_pos-1));
    for (auto out:v)
        cout << out << " ";

    cin >> del_element_range_1 >> del_element_range_2;
    v.erase (v.begin () + (del_element_range_1-1), v.begin () + (del_element_range_2-1));

    cout << v.size () << endl;

    for (auto out:v)
        cout << out << " ";
    
    return 0;
}