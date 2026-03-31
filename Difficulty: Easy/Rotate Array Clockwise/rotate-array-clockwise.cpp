class Solution {
  public:
    void rotateclockwise(vector<int>& arr, int k) {
        // code here
        if(k == arr.size()) return;
        
        int it =k %  arr.size();
        int start = arr.size() - it;
        
        vector<int> ans;
        
        for(int i= start ; i < arr.size(); i++){
            ans.push_back(arr[i]);
        }
        
         for(int i= 0 ; i < start; i++){
            ans.push_back(arr[i]);
        }
        
        
        arr = ans;
        
    }
};
