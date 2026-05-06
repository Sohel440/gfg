//Let's start with the name of Allah


#include <iostream>
using namespace std;

void change(int *num){
    // cout << &num << endl;
    *num =10;
    
    
}
int main(){

    int a = 10;
    
    int *p = &a;

    int **pp = &p;

    // cout << "pp  value is: "<< *pp << endl;
    // cout <<"value:" << a << " address : " << &a << endl;
    // cout <<"value:" << p << " address : " << &p << endl;
    // cout << "value:" << pp << " address: " << &pp << endl;

    int num=9;
    cout << "before num " << num << endl;

    change(&num);
    cout << "after num " << num << endl;
   
    

    int arr[]= {10,20,40};
    cout << *arr+1 << endl;
    cout << &arr << ": "<<  (&arr+1) << endl;



    return 0;
}

