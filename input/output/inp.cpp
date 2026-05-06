#include <bits/stdc++.h>
using namespace std;

vector<int> prime;
void primeSive(int n){

    prime.assign(1e5,1);
    for(int i = 2 ; i * i <= n ; i++){
        if(prime[i]== 1){
            for(int j = i*i ; j <= n ; j+=i){
                prime[j]=0;
            }
        }
    }

    for (int p = 2; p <= n; p++)
        if (prime[p])
            cout << p << " ";

}
void best(){
    string line ;
    getline(cin , line);
    vector<int> arr;

    string numStr ="";
    for(auto t: line){
        if(isdigit(t)){
            numStr += t;
        }else if(!numStr.empty()){
            arr.push_back(stoi(numStr));
            numStr="";
        }
    }

    if(!numStr.empty()){
        arr.push_back(stoi(numStr));
        numStr = "";
    }


    for(auto t: arr){
        cout << t << " ";
    }
    cout << endl;
}
int main(){

//    vector<int> arr;
//    int num;
//    while(cin>> num){
//     arr.push_back(num);
//    }
//    for(auto t: arr){
//     cout << t <<  " ";
//    }
//    cout << endl;

// primeSive(100);

    // string line ;
    // getline(cin , line);

    // string numstr="";
    // vector<int> arr;

    // for(auto t: line){
    //     if(isdigit(t)){
    //         numstr+=t;
    //     }else if(!numstr.empty()){
    //         arr.push_back(stoi(numstr));
    //         numstr ="";
    //     }
    // }
    // if(!numstr.empty()){
    //     arr.push_back(stoi(numstr));
    // }

    // for(auto t: arr){
    //         cout << t <<  " ";
    //        }

    string s;
    cin >> s;

    map<char , int> mp;;
    for(auto t: s){
        mp[t]++;
    }

    string nonr ="";
    for(int i= 0;i < s.size() ; i++){
        if(mp[s[i]] == 1){
         if(nonr =="")   nonr += (s[i]);
            break;
        }
    }

    if(nonr != "")cout << nonr;else cout << "None";
    string rep  = "";
    int mx =0;
    for(int i =0 ;i < s.size(); i++){
        if(mx < mp[s[i]]){
            rep  = (s[i]);
            mx = mp[s[i]];
        }
    }
    cout << " "<<rep<< endl;



    return 0;

}