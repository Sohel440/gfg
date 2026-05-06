#include <bits/stdc++.h>
using namespace std;


class Bank{
    private: 
      long long balance;
    public: 
      Bank (long long  balance){
        this->balance = balance;
      }

    public: 
      void deposite(long long money){
        this->balance += money;
      };

      long long getBalance(){
        return this->balance;
      };
      void setBalance(long long num){
        this->balance = num;

      }
};


class Savings : private Bank{

    
    
    public:
    Savings(long long balance):Bank(balance){}
      double getInterest(float a ){
         double num = (a /100) * getBalance() + getBalance();
         setBalance((long long)num);
         return num; 
      }
};


class currentAccount : protected Bank{
    
    public:
     currentAccount(long long balance):Bank(balance){}
      void withDrawn (long long num){
         long long newNum = (long long ) getBalance() -(long long ) num;
         setBalance(newNum);
      }
      void showCurrntAcountDetails(){
        cout << "current a/c amount is : "<< getBalance()<< endl;
      }
      void depositeIntoCurrentAccount(long long num){
        long long money = getBalance() + num;
        setBalance(money);
      }
      

      
};



int main(){

    currentAccount  sohel(2000);
    sohel.withDrawn(100);
    sohel.showCurrntAcountDetails();
    sohel.depositeIntoCurrentAccount(200);
    sohel.showCurrntAcountDetails();



    Savings sabnam (20000);
    cout << sabnam.getInterest(10)<< endl;;

    vector<Savings> arr;
    

}