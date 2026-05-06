#include <bits/stdc++.h>
using namespace std;

class vichel{
    private:
       string name;
       string num;
       string colour;
       long long price;

    public : 
       vichel(string name ,string num , string colour , long long price){
         this->name = name;
         this -> num = num;
         this->colour = colour ;
         this->price = price;

       }

       long long getPrice(){
        return this->price;
       }
       void setPrice(long long n){
        this->price = n;
       }
       string CarNO(){
        return this->num;
       }
       string vichelName(){
        return this->name;
       }

       virtual void getDiscount(int n)=0;

       void printInfo(){
        cout << name << " on the way guys!";
       }

};


class Car : public vichel{
    private:
    int wheel;
    public: 
        Car(string name ,string num , string colour , long long price , int wheel): vichel (name , num , colour , price  ){
            this->wheel =wheel;
   
        }

        int getWheel (){
            return this->wheel;

        } 
        void getDiscount(int n){
            int price = getPrice();
            double discount = n /100.0;
            double total = price - (price*discount);
            long long val = total;

            setPrice(val);
        }
    
};

int main(){

    Car Thar("Thar","123","red",20000, 4);
    cout << Thar.vichelName() << endl;
    cout << Thar.getPrice() <<endl;
    Thar.printInfo();
    cout << "\n";

    cout <<  Thar.getWheel()<< endl;
    Thar.getDiscount(5);
    cout << Thar.getPrice() <<endl;


    return 0;
}
