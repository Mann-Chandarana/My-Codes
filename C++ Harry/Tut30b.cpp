#include <iostream>
#include <math.h>
using namespace std;

class Point
{
    int x, y;

public:
    Point(int a, int b)
    {
        x = a;
        y = b;
    }
    friend void distance(Point, Point);

    void displayPoint()
    {
        cout << "The point is (" << x << ", " << y << ")" << endl;
    }
};

// Create a function (Hint: Make it a friend function) which takes 2 point objects and computes the distance between those 2 points

void distance(Point o1, Point o2)
{
    double x_distance = pow(o1.x - o2.x, 2);
    double y_distance = pow(o1.y - o2.y,2);
    int distance = sqrt(x_distance + y_distance);
    cout << distance;
}

int main()
{
    Point p(1, 0);
    p.displayPoint();

    Point q(70, 0);
    q.displayPoint();

    distance(p, q);

    return 0;
}
