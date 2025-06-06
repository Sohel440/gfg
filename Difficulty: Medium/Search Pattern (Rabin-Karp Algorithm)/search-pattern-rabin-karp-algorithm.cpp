class Solution {
  public:
    vector<int> search(string &pat, string &txt) {
        // code here.
        vector<int> arr(pat.size(), 0) , pre(txt.size(), 0);
        arr[0] = pat[0]-'a';
        
        pre[0] = txt[0]-'a';
        
        for(int i = 1 ; i < pat.size(); i++){
            arr[i] = pat[i]-'a' + arr[i-1];
        }
        
        for(int i = 1 ; i < txt.size(); i++){
            pre[i] = txt[i]-'a' + pre[i-1];
        }
        
        
        vector<int> ans;
        int k = pat.size()-1;
        
        for(int i =k ; i < txt.size(); i++){
            int val ;
            if(i == k) val = pre[k];
            else val = pre[i] - pre[i-k-1];
           // cout << val << " "<< arr[pat.size()-1] << endl;
            if(val == arr[pat.size()-1]){
                
                int ts = i-k;
                int ps =0;
                while(ts < txt.size() && ps < pat.size()){
                    if(txt[ts] != pat[ps])break;
                    ts++;
                    ps++;
                }
                if(ps >=pat.size())ans.push_back(i-k+1);
                
            }
        }
        
        return ans;
        
    }
};