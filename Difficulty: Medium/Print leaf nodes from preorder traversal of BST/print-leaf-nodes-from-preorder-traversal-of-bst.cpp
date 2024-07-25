//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val)
        : data(val)
        , left(nullptr)
        , right(nullptr) {}
};
class Solution {
  public:
    vector<int> ans;
    void preOrder(Node*root ){
        if(!root) return;
        
        if(root->left == NULL && root->right == NULL){
            ans.push_back(root->data);
            
        }
      //  cout << root->data << endl;
        
        preOrder(root->left);
        preOrder(root->right);
        
    }
    Node* build(int  &i  , int bound , int arr[], int N){
         if(i == N || arr[i]  > bound) return NULL;

        
        Node * root = new Node(arr[i++]);
        
        root->left = build(i , root->data , arr, N);
        root->right = build(i , bound , arr , N);
        
        return root;
        
    }
    vector<int> leafNodes(int arr[],int N) {
        // code here
        int i=0;
        Node * root = build(i , 1e9 , arr , N);
        preOrder(root);
        return ans;
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for(int i=0;i<N;i++)cin>>arr[i];
        Solution ob;
        vector<int>ans=ob.leafNodes(arr,N);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends