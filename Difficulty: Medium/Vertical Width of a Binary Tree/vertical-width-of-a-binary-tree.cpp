//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

// Function to Build Tree
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

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
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

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//Back-end complete function Template for C++
class Solution {
  public:
    // Function to find the vertical width of a Binary Tree.
vector<pair<int, int>> vec;

void bfs(Node *root) {
    if (!root) return;

    queue<pair<pair<int, int>, Node*>> q;
    q.push({{0, 0}, root});
    vec.push_back({0, 0});

    while (!q.empty()) {
        auto it = q.front();
        q.pop();

        int lvl = it.first.first;
        int cor = it.first.second;
        Node *newnode = it.second;

        if (newnode->left) {
            q.push({{lvl + 1, cor - 1}, newnode->left});
            vec.push_back({lvl + 1, cor - 1});
        }
        if (newnode->right) {
            q.push({{lvl + 1, cor + 1}, newnode->right});
            vec.push_back({lvl + 1, cor + 1});
        }
    }
}

int verticalWidth(Node* root) {
    // Clear vec for each function call
    vec.clear();
    bfs(root);

    if (vec.empty()) return 0;

    // Find minimum and maximum horizontal distances
    int min_cor = vec[0].second;
    int max_cor = vec[0].second;

    for (const auto& p : vec) {
        if (p.second < min_cor) {
            min_cor = p.second;
        }
        if (p.second > max_cor) {
            max_cor = p.second;
        }
    }

    return max_cor - min_cor + 1;
}
};


//{ Driver Code Starts.
int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string str;
        getline(cin, str);
        Solution obj;
        Node *root = buildTree(str);

        cout << obj.verticalWidth(root) << "\n";
    }

    return 0;
}

// } Driver Code Ends