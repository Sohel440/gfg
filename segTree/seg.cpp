#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10 ;
int seg[4*N];
int a[N];


void Build(int ind , int low , int high){

    if(low == high){
        seg[ind]=  a[low];
        return;
    }
    int mid  = (low + high)/2;
    Build(2*ind+1 , low , mid);
    Build(2*ind+2, mid+1 , high);;

    seg[ind] = max(seg[2*ind+1], seg[2*ind +2]);

}

int query(int ind , int low , int high , int l , int r){
    if(low >= l && high<= r){
        return seg[ind];
    }
    if(low > r || high < l){
        return INT_MIN;
    }

    int mid =(low+high)/2;
    int left = query(2*ind +1 , low ,mid , l , r);
    int right = query(2*ind +2 , mid+1 , high , l , r);

    return max(left , right);
}
void pointUpdate (int ind , int low  , int high , int node , int val){

    if(low == high){
        seg[ind] = val;
    }else{
        int mid = (low + high)>> 1;
        if(node <=mid && node >= low) pointUpdate(2*ind + 1 , low , mid , node , val);
        else pointUpdate(2*ind + 2 , mid +1 , high , node ,val);

        seg[ind]= max(seg[2*ind + 1] , seg[2*ind+2]);
    }
}
void kaj(){
    int n;
    cin >> n;
    

    for(int i= 0 ; i < n ; i++){
        cin >> a[i];
    }

    Build(0 , 0 , n-1);
    pointUpdate(0, 0 , n-1, 1 , 2);
    cout << query(0, 0,n-1,0,2) << endl;
    pointUpdate(0, 0,n-1, 2 , 5);
    cout << query(0, 0,n-1,0,2)<< endl;;
    cout << __gcd(4,6)<< endl;
    cout << (4*6)/__gcd(4,6) << endl;;


}
int main(){
    
        kaj();
   
    return 0;
}