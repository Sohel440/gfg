#include  <bits/stdc++.h>
using namespace std;

class Shape{
    private:

    public:
      virtual  void area()=0;
};

class Circle : public Shape{
    private:
      int r ;

    public: 
      Circle(int r){
        this->r = r;
      }
      void area(){
         cout << "Area : "<< (3.14 * pow(this->r, 2))<< endl;;
      }
};
class Rectangle : public Shape{
    private:
      int l , w;

    public: 
      Rectangle(int l , int w){
        this->l = l;
        this->w = w;


      }
      void area(){
         cout << "Area : "<< (this->l * this->w)<< endl;;
      }
};


void ShapArea(Shape *s){
    s->area();
}

int main(){

    Shape *s;

    Rectangle r(10 ,12);
    Circle c(5);

   ShapArea(&r);
   ShapArea(&c);



}