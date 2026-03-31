class Solution {
  public:
    void rotateArr(vector<int>& arr, int d) {
        // code here
        
        vector<int> ans;
        int start = d % arr.size() ;
        
        for(int i = start ; i < arr.size(); i++){
            ans.push_back(arr[i]);
        }
        
        for(int i  = 0 ; i < start ; i++){
            ans.push_back(arr[i]);
        }
        
        arr = ans;
        
    }
};