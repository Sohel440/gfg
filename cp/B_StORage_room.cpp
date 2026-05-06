#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int m[n][n];
        int arr[n];
        for(int i = 0;i < n;i++){
            arr[i] = (1<<30) - 1;
        }
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                cin>>m[i][j];
                if(i != j){
                    arr[i] &= m[i][j];
                    arr[j] &= m[i][j];
                }
            }
        }
        bool ok = true;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                if(i != j && (arr[i] | arr[j]) != m[i][j]){
                    ok = false;
                }
            }
        }
        if(!ok){
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
            for(int i = 0;i < n;i++){
                cout<<arr[i]<<" ";
            }
            cout<<"\n";
        }
    }
}