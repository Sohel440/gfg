#include <bits/stdc++.h>
using namespace std;

class Shape{

    public:
    virtual  void draw(){
        cout << "Shape drawing..."<< endl;
      }
};

class Circle : public Shape{
    public:
      void draw() override{
        cout << "circle is drawing..."<< endl;
      }
      
};
class Rectangle : public Shape{
    public:
       void draw() override{ 
        cout << "Rectangle is drawing..."<< endl;
      }
      
};
class Traingle : public Shape{
    public:
       void draw() override{ 
        cout << "Traingle is drawing..."<< endl;
      }
      
};

void shapeDraw( Shape *g){
    g->draw();
}
int main(){
    Circle c;
    Rectangle r;
    Traingle t;
    
    shapeDraw(&c);
    shapeDraw(&r);
    shapeDraw(&t);

    return 0;

}