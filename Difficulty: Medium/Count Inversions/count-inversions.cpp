//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to count inversions in the array.
    
    int ans =0;
    
    void merge(int l , int mid , int h , vector<int> &arr){
        
        
        int leftSize = mid -l + 1;
        int rightSize = h-mid;
        
        vector<int>left(leftSize), right(rightSize);
        
        for(int i= 0 ; i < leftSize; i++){
            left[i] = arr[l+i];
            
        }
        
        for(int i= 0 ; i < rightSize; i++){
            right[i] = arr[mid+1+i];
        }
        
        
        int k  = l;
        int i =0;
        int j =0;
        
        while(i < leftSize && j < rightSize){
            
            if(left[i] <= right[j]){
                arr[k]= left[i];
                i++;
            }else{
                //cout << left[i]<<" "<< right[j]<< endl;
                arr[k] = right[j];
                j++;
                ans +=(leftSize - i);
            }
            k++;
            
        }
        
        while(i < leftSize){
            
            arr[k] = left[i];
            i++;
            k++;
            
        }
        while(j < rightSize){
            
            arr[k] = right[j];
            j++;
            k++;
        }
        
        
        
        
    }
    void mergeSort(int l , int h , vector<int> &arr){
        
        if(l >= h){
            return ;
        }
        int mid = (l + h)>>1;
        mergeSort(l , mid , arr);
        mergeSort(mid+1 , h , arr);
        
        merge(l  , mid , h , arr);
        
    }
    
//     void printVector(vector<int>& arr)
// {
//     for (int i = 0; i < arr.size(); i++)
//         cout << arr[i] << " ";
//     cout << endl;
// }
    
    int inversionCount(vector<int> &arr) {
        // Your Code Here
        
        mergeSort(0 , arr.size()-1 , arr);
       // printVector(arr);
        return ans;
        
        
    }
};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends