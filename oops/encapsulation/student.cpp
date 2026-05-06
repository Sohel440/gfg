#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_set>
#include <set>


using namespace std;


class Student
{
private:
    double gpa;
    string gf;

public:
    string name ;

    Student(double gpa , string gf , string name){
        this->gf= gf;
        this->name = name;
        this->gpa= gpa;

    }
    public:
    void setGpa(double gpa ){
        this-> gpa = gpa;
    }
    double getGpa( ){
      return this->gpa;
    }
    string getGf( ){
      return this->gf;
    }

    // private:
    // void getGf (){
    //     cout << " Gf name is : " << this->gf<< endl;
    // }
};




int main(){

    Student A(8.8 , "bal","sohel");
    cout << A.name<< endl;
    A.setGpa(7.0);

    cout << A.getGpa()<< endl;
    cout << A.getGf()<< endl;



    return 0;

}



