//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node()
        : data(0)
        , left(NULL)
        , right(NULL) {}

    Node(int x)
        : data(x)
        , left(NULL)
        , right(NULL) {}
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node(val);
    return temp;
}

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input string after splitting by space
    vector<string> ip;
    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {
        Node* currNode = queue.front();
        queue.pop();
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {
            currNode->left = newNode(stoi(currVal));
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {
            currNode->right = newNode(stoi(currVal));
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

/* Function to print nodes in a given doubly linked list */
void printList(Node* node) {
    Node* prev = NULL;
    while (node != NULL) {
        cout << node->data << " ";
        prev = node;
        node = node->right;
    }
    cout << endl;
    while (prev != NULL) {
        cout << prev->data << " ";
        prev = prev->left;
    }
    cout << endl;
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data;
        inorder(root->right);
    }
}


// } Driver Code Ends
/* Structure for tree and linked list

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

// This function should return head to the DLL
class Solution {
  public:
   vector<int> ans;  // To store in-order traversal of the tree
    
    // In-order traversal to get sorted data from BST
    void solve(Node* root) {
        if (root) {
            solve(root->left);  // Traverse left subtree
            ans.push_back(root->data);  // Store the root's data
            solve(root->right);  // Traverse right subtree
        }
    }
    
    // Function to convert binary tree to doubly linked list
    Node* bToDLL(Node* root) {
        if (!root) return nullptr;  // Edge case: If the tree is empty

        // Perform in-order traversal to collect the node values in sorted order
        solve(root);

        // Create a dummy node to simplify the creation of the linked list
        Node* dummy = new Node(0);
        Node* p = dummy;
        
        // Construct the doubly linked list from the in-order traversal
        for (int i = 0; i < ans.size(); i++) {
            p->right = new Node(ans[i]);  // Create new node and link it to the right
            p->right->left = p;  // Link back to the previous node
            p = p->right;  // Move to the next node
        }

        // The head of the doubly linked list will be the node after the dummy
        Node* head = dummy->right;
        if (head) head->left = nullptr;  // Set the left pointer of the head to nullptr
        
        // Delete the dummy node as it's no longer needed
        delete dummy;
        
        return head;  // Return the head of the doubly linked list
    }
};

//{ Driver Code Starts.

/* Driver program to test size function */
int main() {
    int t;
    cin >> t;
    getchar();

    while (t--) {
        string inp;
        getline(cin, inp);
        Node* root = buildTree(inp);

        Solution ob;
        Node* head = ob.bToDLL(root);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends