class Solution {
  public:
    
    bool solve(vector<int> &arr , int mid , int k){
        
        int cnt =0;
        for(int i = 0 ; i < arr.size(); i++){
            if(arr[i] <= mid) cnt++;
            else{
                int tot = arr[i]/mid;
                int rem = arr[i]%mid;
                cnt += tot;
                if(rem >0) cnt++;
            }
        }
        
        return cnt <=k;
    }
    int kokoEat(vector<int>& arr, int k) {
        // Code here
        
        int lo = 1;
        int hi = 1e6;
        
        
        int ans = -1;
        
        
        while(lo <= hi){
            
            int mid = (lo + hi)>>1;
            if(solve(arr , mid ,k)){
                ans = mid;
                hi = mid-1;
                
            }else{
                lo =mid + 1;
            }
        }
        
        return ans;
        
    }
};