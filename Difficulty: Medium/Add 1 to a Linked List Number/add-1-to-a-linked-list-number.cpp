//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data % 10;
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
// User function template for C++

/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    Node* addOne(Node* head) {
        // Your Code here
        // return head of list after adding one
        Node * temp = head;
        vector<int> ans;
        while(temp){
            ans.push_back(temp->data);
            //ans += to_string(temp->data);
            temp = temp->next;
        }
        
       
        
        reverse(begin(ans), end(ans));
        int carry =0;
        
        
        
        carry = (ans[0]+1)/10;
        ans[0] = (ans[0]+1 )%10;
       // cout << carry << endl;
        
        
        for(int i = 1 ; i  < ans.size(); i++ ){
            int val = ans[i];
            ans[i] = (ans[i] + carry) %10 ;
            
            carry = (val+carry) / 10;
           // cout << ans[i]<< " ->" << carry << endl;
           
            
        }
        if(carry){
            ans.push_back(carry);
        }
        reverse(begin(ans), end(ans));
        
        Node * q = new Node(-1);
        Node * p = q;
        
        
        
        for(auto tt : ans){
            q->next  = new Node(tt);
            q = q->next;
        }
        
        return p->next;
        
        
        //return NULL;
        
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends