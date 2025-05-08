#include <iostream>
using namespace std;

class Rectangle {
    int Lenght, Width;
public:

    void Set_dimension(int a, int b) {
        Lenght = a;
        Width = b;
    }


    int Calculate_area() {
        int Area = Lenght * Width;
        return Area;
    }


    int Perimeter() {
        int Perimeter = 2 * (Lenght + Width);
        return Perimeter;
    }
};

int main() {
    Rectangle Rect;
    int Lenght, Width, Area, Perimeter;

    cout << "Enter length and width of Rectangle: ";
    cin >> Lenght >> Width;

    Rect.Set_dimension(Lenght, Width);

    Area = Rect.Calculate_area();
    Perimeter = Rect.Perimeter();


    cout << "The Calculate_area of the rectangle is " << Area
         << " and the Perimeter of the rectangle is " << Perimeter << "." << endl;
    return 0;
}
