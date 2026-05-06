#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canAchieveMinValue(const vector<int>& arr, int n, int k, int minValue) {
    int surplus = 0;
    
    for (int i = 0; i < n; i++) {
        if (arr[i] > minValue) {
            surplus += (arr[i] - minValue) / k; // Surplus created by reducing elements above minValue
        } else if (arr[i] < minValue) {
            surplus -= (minValue - arr[i]); // Surplus needed to bring elements below minValue up
        }
    }
    
    // We can achieve the minimum value if the surplus is non-negative
    return surplus >= 0;
}

// cognizant pb 1:

void kaj (){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0 ;i < n ; i++){
        cin >> arr[i];
    }
    

    bool ok = arr[0] % 2!= 0;
    int ans=0;
    for(int i = 1; i < n ; i++){
        if(arr[i] % 2==0 && ok){
            ans++;
            ok = false;

        }else if(arr[i] % 2 == 1&& ok == false){
            ok = true;
        }
    }
    cout << ans << endl;



}
void cognizant_pb2(){
    int n , m;
    cin >> n >> m;
    int ans =0;

    for(int i = 0 ; i < n ; i++){
        int arr[m] ={0};
        int sum =0;
        for(int p = 0 ; p<m; p++){
            cin >> arr[p];
            if(arr[p] % 2 != 0) sum += arr[p];
        }
        if(sum % 2 ==0){
            ans ++;
        }
    }

    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--)
    {
        cognizant_pb2();
    }
    
    
    return 0;
}
