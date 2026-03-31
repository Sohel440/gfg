class Solution {
  public:
    int findEquilibrium(vector<int> &arr) {
        // code here
        int sum = accumulate(arr.begin(), arr.end(), 0);
      //  cout << sum << endl;
        
        int start = arr[0];
        
        for(int i= 1 ; i < arr.size(); i++){
            
            start += arr[i];
            
            if(sum - start == start- arr[i])return i;
            
            
        }
        
        return -1;
    }
};