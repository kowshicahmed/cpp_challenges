#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


class Person
{
    string name;
    int age;
public:
// Constructors and destructors
    Person (string name, int age) : name{name}, age{age} {}
    Person () : Person ("Unknown", 0) {}
    virtual ~Person() = default;
// Virtual functions
    virtual void getdata () = 0;
    virtual void putdata () = 0;
    string get_name () {return name;}
    int get_age() {return age;}

    void set_name (string n) {name = n;}
    void set_age (int a) {age = a;}
};

class Professor : public Person
{
    int publications;
    static int cur_id;
public:
// Constructors and destructors
    Professor (string name, int age, int pub) 
        : Person{name, age}, publications{pub} 
    {
    }
    Professor () : Professor("None", 0, 0) {}
// virtual overrided functions
    virtual void getdata () override
    {
        string name {};
        int age {};
        int publ{};
        cin >> name >> age >> publ;
        this->Person::set_name(name);
        this->Person::set_age(age);
        this->publications = publ;
    }
    virtual void putdata () override
    {
        Professor::cur_id+=1;
        cout << this->get_name() << " " << this->get_age() 
        << " " << this->publications << " " << Professor::cur_id << endl; 
    }


};

class Student : public Person
{
    int marks [6];
    static int cur_id;
public:
// constructor
    Student (string name, int age) 
        : Person{name, age} 
    {
    }
    Student () : Student("None", 0) {}
// virtual overrided functions
    virtual void getdata () override
    {
        string name {};
        int age {};
        int mark;
        cin >> name >> age;
        for (int i{}; i < 6; i++)
        {
            cin >> mark;
            marks[i] = mark;
        }
        this->Person::set_name(name);
        this->Person::set_age(age);
    }
    virtual void putdata () override
    { 
        Student::cur_id+=1;
        int sum {};
        for (int i{}; i < 6; i++)
        {
            sum +=marks[i];
        }
        cout << this->get_name() << " " << this->get_age() << " "
            << sum << " " << Student::cur_id << endl;
    }

};

int Professor::cur_id = 0;
int Student::cur_id = 0;

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
