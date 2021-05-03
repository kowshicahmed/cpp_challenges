#include <iostream>
#include <vector>
#include <cctype>
#include <cstring>

using namespace std;

/* This is a menu driven data structure
 * User can store int numbers to vectors
 * According to user choice different tasks can be performed on numbers
 * */

//functions prototypes
void display_menu ();
char input_handler (char &selection);
void function_caller (char &selection, vector <int> &numbers);
void print_numbers (vector <int> &numbers);
void add_numbers (vector <int> &numbers);
void mean_of_numbers (vector <int> &numbers);
void smallest_number (vector <int> &numbers);
void largest_number (vector <int> &numbers);

int main()
{
    vector <int> numbers {};
    char selection {0};
    
    do
    {
        display_menu ();
        selection = input_handler(selection);
        
        function_caller (selection, numbers); 
        
    } while (selection != 'q' && selection != 'Q');
    
    
    
	return 0;
}

void display_menu ()
{
    //Display menu
    cout << "\nP - Print numbers" << endl;
    cout << "A - Add a number" << endl;
    cout << "M - Display mean of the numbers" << endl;
    cout << "S - Display the smallest number" << endl;
    cout << "L - Display the largest number" << endl;
    cout << "Q - Quit" << endl;
}

char input_handler (char &selection)
{
    cin >> selection;
    
    return toupper(selection);
}

void print_numbers (vector <int> &numbers)
{
    if (numbers.size() == 0)
            {
                cout << "[] - the list is empty" << endl;
            }
            else
            {
                cout << "[ ";
                for (auto num: numbers)
                {
                    cout << num << " ";
                }
                cout << "]" << endl;
            }
}

void add_numbers (vector <int> &numbers)
{
    int num_to_add {};
    cout <<"Enter an int to add: ";
    cin >> num_to_add;
    numbers.push_back(num_to_add);
    cout << num_to_add << " added" <<endl;
}

void mean_of_numbers (vector <int> &numbers)
{
    if (numbers.size() == 0)
    {
        cout << "unable to calculate" << endl;
    }
    else 
    {
        int total {};
        for (auto num: numbers)
        {
            total+= num;
        }
        cout << "The mean is: " << static_cast<double>(total)/numbers.size() << endl;
    }
}

void smallest_number (vector <int> &numbers)
{
    if (numbers.size() == 0)
    {
        cout << "Unable-list is empty" << endl;
    }
            
    else
    {
        int smallest = numbers.at(0);
        for (auto num: numbers)
        {
            if (num < smallest)
            {
                smallest = num;
            }
        }
        cout << "The smallest number is: " << smallest << endl;
    }
}

void largest_number (vector <int> &numbers)
{
    if (numbers.size() == 0)
    {
        cout << "unable-list is empty";
    }
            
    else
    {
        int largest = numbers.at(0);
                
        for (auto num: numbers)
        {
            if (num > largest)
            {
                largest = num;
            }
        }
                
        cout << "The largest number is: " << largest << endl;
    }
}

void function_caller (char &selection, vector <int> &numbers)
{
    //print the number is [ 1 2 3 ] fashion
    if (selection == 'P')
        {
            print_numbers (numbers);
        }
        
        //Add user given numbers to the array
        else if (selection == 'A')
        {
            add_numbers (numbers);
        }
        
        //Calculate and show the mean
        else if (selection == 'M')
        {
            mean_of_numbers (numbers);
        }
        
        //Show the smallest number
        else if (selection == 'S')
        {
            smallest_number (numbers);
        }
        
        //Show the largest number
        else if (selection == 'L')
        {
            largest_number (numbers);
        }
        
        else if (selection == 'Q')
        {
            cout << "Goodbye" << endl;
        }
        
        else
        {
            cout << "Invalid input" << endl;
        }
}