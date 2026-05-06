#include<bits/stdc++.h>
using namespace std;

class DSU
{
public:
vector <int> par , rank , size;
DSU(int n ){
    
    par.resize(n+1 , 0);
    rank.resize(n+1 , 0);
    size.resize(n+1 , 0);

    for(int i = 0 ;i <= n ;i++){
        par[i] = i;
        rank[i] =0;
        size[i] =1;
    }
}

int find(int n){
    if(par[n] == n){
        return n;
        
    }

    return par[n] = find(par[n]);
}

void UnionbyRank(int u , int v){
    int ulb_u = find(u);
    int ulb_v = find(v);
    if(ulb_u == ulb_v) return;
    
    if(rank[ulb_u] > rank[ulb_v]){

        par[ulb_v] = ulb_u;
    }else if(rank[ulb_u] < rank[ulb_v]){
        par[ulb_u] = ulb_v;
    }else{

        par[ulb_u] = ulb_v;
        rank[ulb_v]++;
    }
}
void UnionbySize(int u , int v){
    int ulb_u = find(u);
    int ulb_v = find(v);
    if(ulb_u == ulb_v) return;
    
    if(size[ulb_u] < size[ulb_v]){
        par[ulb_u] = ulb_v;
        size[ulb_v] += size[ulb_u];
    }else{
        par[ulb_v] = ulb_u;
        size[ulb_u] += size[ulb_v];
    }
    
}
   
};

int main(){
  int n ;
  cin >> n;
    DSU ds (7);
    // ds.UnionbyRank(1,2);
    // ds.UnionbyRank(2,3);
    // ds.UnionbyRank(4,5);
    // ds.UnionbyRank(6,7);
    
    // if(ds.find(3) == ds.find(7)){
    //     cout << "SAME" << endl;
    // }else{
    //     cout << "NOT SAME" << endl;
    // }
    // ds.UnionbyRank(3,7);
    //  if(ds.find(3) == ds.find(7)){
    //     cout << "SAME" << endl;
    // }else{
    //     cout << "NOT SAME" << endl;
    // }

    //union by size

    
    ds.UnionbySize(1,2);
    ds.UnionbySize(2,3);
    ds.UnionbySize(4,5);
    ds.UnionbySize(6,7);

    if(ds.find(3) == ds.find(7)){
        cout << "SAME" << endl;
    }else{
        cout << "NOT SAME" << endl;
    }
    ds.UnionbySize(3,7);

     if(ds.find(3) == ds.find(7)){
        cout << "SAME" << endl;
    }else{
        cout << "NOT SAME" << endl;
    }


    return 0;

}

