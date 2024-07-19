//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<int> Smallestonleft(int arr[], int n);

int main() {

    int t;

    cin >> t;

    while (t--) {

        int n;
        cin >> n;
        int arr[n + 1];

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        vector<int> b;
        b = Smallestonleft(arr, n);
        for (int i = 0; i < n; i++)
            cout << b[i] << " ";

        cout << endl;
    }

    return 0;
}
// } Driver Code Ends


vector<int> Smallestonleft(int arr[], int n) {
    // Complete the function
    vector<int> ans(n , 0);
    int prev = arr[0];
    
    ans[0] = -1;
    multiset<int> mt;
    mt.insert(arr[0]);
    
    for(int i = 1 ; i < n ; i++){
        int value = arr[i];
        
            auto it = mt.lower_bound(value);

    if (it == mt.begin() && *it >= value) {
        ans[i] = -1;
        
        // No elements are less than `value`
       // std::cout << "No elements less than " << value << std::endl;
    } else {
        // If it == ms.end(), move it one step back
        if (it == mt.end() || *it >= value) {
            --it;
        }
        ans[i] = *it;
       // std::cout << "Largest element less than " << value << " is " << *it << std::endl;
    }

        
        
        mt.insert(value);
        
    }
    
    return ans;
}


/*
   auto it = ms.lower_bound(value);

    if (it == ms.begin()) {
        // No elements are less than `value`
        std::cout << "No elements less than " << value << std::endl;
    } else {
        // Move the iterator one step back to get the largest element less than `value`
        --it;
        std::cout << "Largest element less than " << value << " is " << *it << std::endl;
    }*/