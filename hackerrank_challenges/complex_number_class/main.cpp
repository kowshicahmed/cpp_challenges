#include <iostream>
#include <string>

using namespace std;

class Complex
{
    //> Overloaded insertion and extraction operator
    friend std::ostream &operator<<(std::ostream &os, const Complex &rhs);
    friend std::istream &operator>>(std::istream &is, Complex &rhs);
private:
    int a,b;
public:
    //> Constructors
    Complex (int x, int y)
        :a{x}, b{y} {}
    Complex ()
        : Complex(0,0) {}
    //> Function to covert the string to numbers
    void input(string s);
    //> Overloaded + operator
    Complex operator+(const Complex &rhs) const;
};

//overloaded insertion
std::ostream &operator<<(std::ostream &os, const Complex &rhs)
{
    os << rhs.a <<"+i" << rhs.b;
    return os;
}

//extraction, not actually needed in this probelm
std::istream &operator>>(std::istream &is, Complex &rhs)
{
    int x {}, y{};
    is >> x >> y;
    rhs = Complex {x,y};
    return is;
}

int main()
{
    Complex x,y;
    string s1,s2;
    cin>>s1;
    cin>>s2;
    x.input(s1);
    y.input(s2);
    Complex z=x+y;
    cout<<z<<endl;

    return 0;
}

void Complex::input (string s)
{
    int v1=0;
        int i=0;
        while(s[i]!='+')
        {
            v1=v1*10+s[i]-'0';
            i++;
        }
        while(s[i]==' ' || s[i]=='+'||s[i]=='i')
        {
            i++;
        }
        int v2=0;
        while(i<s.length())
        {
            v2=v2*10+s[i]-'0';
            i++;
        }
        a=v1;
        b=v2;
}

Complex Complex::operator+(const Complex &rhs) const
{
    int real = this->a + rhs.a;
    int img = this->b + rhs.b;
    Complex temp{real,img};
    return temp;
}