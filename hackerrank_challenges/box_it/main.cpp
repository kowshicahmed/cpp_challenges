#include <iostream>

using namespace std;

//Implement the class Box
//l,b,h are integers representing the dimensions of the box

// The class should have the following functions :

// Constructors:
// Box();
// Box(int,int,int);
// Box(Box);

// int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box

//Overload operator < as specified
//bool operator<(Box& b)

//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)

class Box
{
    friend std::ostream &operator<<(std::ostream &os, const Box &rhs);

private:
    int l;
    int b;
    int h;

public:
    Box() : l{0}, b{0}, h{0} {}
    Box(int length, int breadth, int height)
        : l{length}, b{breadth}, h{height}
    {
    }
    Box(const Box &source)
        : Box{source.l, source.b, source.h}
    {
    }
    int getLength()
    {
        return l;
    }
    int getBreadth()
    {
        return b;
    }
    int getHeight()
    {
        return h;
    }
    long long CalculateVolume()
    {
        return static_cast<long long>(l) * b * h;
    }
    bool operator<(const Box &rhs) const
    {
        if (this->l < rhs.l)
            return true;
        else if (this->b < rhs.b && this->l == rhs.l)
            return true;
        else if (this->h < rhs.h && this->b == rhs.b && this->h == rhs.h)
            return true;
        else
            return false;
    }
};

std::ostream &operator<<(std::ostream &os, const Box &rhs)
{
    os << rhs.l << " " << rhs.b << " " << rhs.h;
    return os;
}

void check2()
{
    int n;
    cin >> n;
    Box temp;
    for (int i = 0; i < n; i++)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            cout << temp << endl;
        }
        if (type == 2)
        {
            int l, b, h;
            cin >> l >> b >> h;
            Box NewBox(l, b, h);
            temp = NewBox;
            cout << temp << endl;
        }
        if (type == 3)
        {
            int l, b, h;
            cin >> l >> b >> h;
            Box NewBox(l, b, h);
            if (NewBox < temp)
            {
                cout << "Lesser\n";
            }
            else
            {
                cout << "Greater\n";
            }
        }
        if (type == 4)
        {
            cout << temp.CalculateVolume() << endl;
        }
        if (type == 5)
        {
            Box NewBox(temp);
            cout << NewBox << endl;
        }
    }
}

int main()
{
    check2();
}