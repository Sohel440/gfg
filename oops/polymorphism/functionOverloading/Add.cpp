#include <bits/stdc++.h>
using namespace std;
// function overloading

class Add
{
public:
    int add(int x, int y)
    {
        cout << "Add two int: \n"
             << endl;
        return x + y;
    }
    int add(int x, int y, int z)
    {
        cout << "Add three int: \n"
             << endl;
        return x + y + z;
    }
    double add(double x, double y)
    {
        cout << "Add two double: \n"
             << endl;
        return x + y;
    }
};

class Complex{
    private:
      int x , y;

    public :
      Complex(int x , int y){
        this->x = x;
        this->y = y;
      }

      void print(){
        cout << "{ "<< this->x << " + i"<< this->y<<" }"<< endl;

      }

      Complex operator+(const Complex &a){
        Complex c (0 , 0);
        int real = this->x + a.x;
        int imag = this->y + a.y;
        c.x = real;
        c.y = imag;

        return c;
      }
      Complex operator-(const Complex &a){
        Complex c (0 , 0);
        int real = this->x - a.x;
        int imag = this->y - a.y;
        c.x = real;
        c.y = imag;

        return c;
      }
};


int main()
{
 
    // Add add;
    // cout << add.add(12, 10) << endl;
    // cout << add.add(12.9, 10.1) << endl;

    Complex a(12, 30);
    Complex b(10, 5);
    a.print();
    b.print();

    Complex c = a + b;
    Complex d = a - b;
    c.print();
    d.print();


    return 0;
}