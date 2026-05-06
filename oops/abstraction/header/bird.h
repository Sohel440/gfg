#if !defined(Bird_M)
#define Bird_M
#include <bits/stdc++.h>
using namespace std;

class Bird{

    private:

    public:
      
      virtual void fly() =0;
      virtual void eat()=0;

};

class Eagle : public Bird{
 
    public: 
       void fly() override {
           cout << "Eagle fly..."<< endl;
       }
       void eat() override {
           cout << "Eagle eat..."<< endl;
       }
};

class Sparrow : public Bird{
 
    public: 
       void fly() override {
           cout << "Sparrow fly..."<< endl;
       }
       void eat() override {
           cout << "Sparrow eat..."<< endl;
       }
};




#endif // MACRO
