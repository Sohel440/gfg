//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
  
     void Graph(Node* root , unordered_map<int, vector<int>> &adj ,   unordered_map<int , bool >& vis){
           //unordered_map<int,vector<int>> adj;
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            
            auto it = q.front();
            
            q.pop();
            
            vis[it->data]= false;
            
            if(it->left){
                adj[it->data].push_back(it->left->data);
                adj[it->left->data].push_back(it->data);
                q.push(it->left);
                
                
            }
            
            if(it->right){
                adj[it->data].push_back(it->right->data);
                adj[it->right->data].push_back(it->data);
                q.push(it->right);
            }
        }
        
     }
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        unordered_map<int,vector<int>> adj;
        unordered_map<int , bool > vis;
        
        Graph(root , adj , vis);
        
        
        queue<int> q;
        q.push(target);
        vis[target] = true;
        int cnt =0;
        
         while (!q.empty()) {
        int size = q.size();  // Process one level at a time

        for (int i = 0; i < size; i++) {
            int it = q.front();
            q.pop();

            for (int v : adj[it]) {
                if (!vis[v]) {
                    q.push(v);
                    vis[v] = true;
                }
            }
        }

        if (!q.empty()) {
            cnt++;  // Increment time only if there's another level to process
        }
    }
        return cnt;
        
        
      
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends