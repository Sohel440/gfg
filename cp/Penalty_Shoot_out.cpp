#include <iostream>
#include <string>
using namespace std;

int main() {
   

  
    for(int i=1; i<=1000000; i++) {
	    string s;
	    cin >> s;
	    if (cin.eof() || cin.fail()) {
	        break;
	    }
          int ans =0;
    int a =-1;

    int misa = 5 , misb=5;
    int ta =0 ,tb = 0;

    for(int i = 0 ; i < 10 ; i++){
        if(s[i] == '1' and i %  2 ==0){
            ta++;

        }else if(s[i] == '0' and i % 2 ==0){
            misa--;

        }else if(s[i]== '1' and i %2 != 0){
            tb++;
        }else if(s[i] == '0' and i %  2 != 0){
            misb--;
        }

        if(ta > misb || tb > misa){

            if(ta > tb) {cout << "TEAM A " << i+ 1 << endl; break;}
            else if(tb > ta) {cout << "TEAM B "<< i + 1 << endl;break;}
           // else cout << "TIE" << endl;break;

        }
    }

    if( ta == tb){
        for(int i = 10 ;  i < 20 ; i+= 2){
            int a = s[i];
            int b = s[i+1];

            if(a == '1'){
                ta++;
            }
            if(b == '1'){
                tb++;
            }

            if(ta > tb ){
                cout << "TEAM A "<< i+2 << endl;
                break;
                
            }
            else if(tb > ta){
                cout << "TEAM B "<< i+2 << endl;
                break;
            }else if(i == 18 and ta == tb){
                cout << "TIE"<< endl;
            }
        }
    }
       
    }
   

    return 0;
}