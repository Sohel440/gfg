//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *right, *down;

    Node(int x) {
        data = x;
        right = NULL;
        down = NULL;
    }
};


// } Driver Code Ends
/*structure of the node of the linked list is as

struct Node
{
    int data;
    Node* right, *down;

    Node(int x){
        data = x;
        right = NULL;
        down = NULL;
    }
};
*/

// function must return the pointer to the first element of the in linked list i.e. that
// should be the element at arr[0][0]
class Solution {
  public:
    Node* constructLinkedMatrix(vector<vector<int>>& mat) {
        // code Here
        
           vector<vector<Node*>> arr;
           for(int i= 0  ; i< mat.size(); i++){
               vector<Node*> t;
               Node *temp = new Node(mat[0][0]);
               t.push_back(temp);
               //<< temp->data << " ";
               for(int j = 1 ; j < mat[0].size(); j++){
                   
                   temp->right = new Node(mat[i][j]);
                   temp = temp->right;
                   t.push_back(temp);
                   //cout<< temp->data << " ";

               }
              // cout << endl;
               arr.push_back(t);
               
           }
           
            for(int i  = 0 ; i < arr.size() ; i ++){
               for(int j = 0 ; j < arr[0].size() ; j++){
                   arr[i][j]->data = mat[i][j];
               }
               
           }
           for(int i  = 0 ; i < arr.size() ; i ++){
               for(int j = 0 ; j < arr[0].size()-1 ; j++){
                   //cout << arr[j][i]->data << " " << arr[j+1][i]->data<< endl;
                   arr[j][i] ->down = arr[j+1][i];
               }
              // cout << endl;
           }
           return arr[0][0];
           
           
    }
};

//{ Driver Code Starts.

void display(Node* head) {
    Node* Rp;
    Node* Dp = head;
    while (Dp) {
        Rp = Dp;
        while (Rp) {
            cout << Rp->data << " ";
            if (Rp->right)
                cout << Rp->right->data << " ";
            else
                cout << "null ";
            if (Rp->down)
                cout << Rp->down->data << " ";
            else
                cout << "null ";
            Rp = Rp->right;
        }
        Dp = Dp->down;
    }
}

// Driver program
int main() {
    int t;
    cin >> t;
    cin.ignore(); // To handle new line after integer input

    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;

        // Read the first row of the matrix
        while (ss >> num) {
            nums.push_back(num);
        }

        int n = nums.size();
        vector<vector<int>> mat(n, vector<int>(n));
        mat[0] = nums;

        // Read the remaining rows of the matrix
        for (int i = 1; i < n; i++) {
            string line;
            getline(cin, line);
            stringstream ss(line);
            vector<int> nums;
            int num;

            // Read the first row of the matrix
            while (ss >> num) {
                nums.push_back(num);
            }

            mat[i] = nums;
        }

        Solution ob;
        Node* head = ob.constructLinkedMatrix(mat);
        if (!head) {
            cout << "-1\n";
        } else {
            display(head);
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends