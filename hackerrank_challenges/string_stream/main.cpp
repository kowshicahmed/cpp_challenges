#include <sstream>
#include <vector>
#include <iostream>

/**In this challenge, we work with string streams
 * stringstream is a stream class to operate on strings
 * It implements input/output operations on memory (string) based streams.
 * stringstream can be helpful in different type of parsing. The following operators/functions are commonly used here
 * Operator >> Extracts formatted data
 * Operator << Inserts formatted data.
 * Method str() Gets the contents of underlying string device object.
 * Method str(string) Sets the contents of underlying string device object.
 * Its header file is sstream.
 * One common use of this class is to parse comma-separated integers from a string
 * stringstream ss("23,4,56");
 * char ch;
 * int a, b, c;
 * ss >> a >> ch >> b >> ch >> c;  // a = 23, b = 4, c = 56
 * Function Description
 * Complete the parseInts function in the editor below.
 * parseInts has the following parameters:
 * string str: a string of comma separated integers
 * Returns
 * vector<int>: a vector of the parsed integers.
 * */

using namespace std;

vector<int> parseInts(string str)
{
    stringstream ss(str);
    vector<int> result;
    char ch;
    int tmp;
    while (ss >> tmp)
    {
        result.push_back(tmp);
        ss >> ch;
    }
    return result;
}

int main()
{
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for (int i = 0; i < integers.size(); i++)
    {
        cout << integers[i] << "\n";
    }

    return 0;
}