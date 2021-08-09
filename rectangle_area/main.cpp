#include <iostream>

using namespace std;
/*
 * Create classes Rectangle and RectangleArea
 */
class Rectangle
{
protected:
    int width;
    int height;
public:
    Rectangle (int w, int h)
        :width(w), height(h)
    {
    }
    Rectangle()
        :Rectangle (0,0)
    {
    }
    void display ()
    {
        cout<< width << " " << height << endl;
    }
    int get_width () {return width;}
    int get_height() {return height;}
};
class RectangleArea : public Rectangle
{
public:
    void read_input()
    {
        cin >> width >> height;
    }
    void display ()
    {
        cout << height * width;
    }
};

int main()
{
    /*
     * Declare a RectangleArea object
     */
    RectangleArea r_area;
    
    /*
     * Read the width and height
     */
    r_area.read_input();
    
    /*
     * Print the width and height
     */
    r_area.Rectangle::display();
    
    /*
     * Print the area
     */
    r_area.display();
    
    return 0;
}