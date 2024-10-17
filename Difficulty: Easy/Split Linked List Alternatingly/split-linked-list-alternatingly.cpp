//{ Driver Code Starts
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


// } Driver Code Ends
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
    // Function to split a linked list into two lists alternately
    vector<Node*> alternatingSplitList(struct Node* head) {
        // Your code here
        vector<int> odd;
        vector<int> even , a;
        
        Node * temp = head;
        while(temp){
            a.push_back(temp->data);
            temp = temp->next;
        }
        
        for(int i = 0 ; i <a.size(); i++){
            if(i % 2 ==0){
                even.push_back(a[i]);
            }else{
                odd.push_back(a[i]);
            }
        }
        
        Node * p = new Node(-1);
        Node * q = p;
        for(auto tt: even){
            p->next = new Node(tt);
            p = p ->next;
            
        }
        
        Node * p1 = new Node(-1);
        Node* q1 =p1;
        
        for(auto tt: odd){
          //  cout << tt << " ";
            p1->next = new Node(tt);
            p1 = p1 ->next;
            
        }
       // return {q1->next};
       // cout << endl;
        vector<Node*>ans;
        ans.push_back(q->next);
        ans.push_back(q1->next);
        return ans;
        
        
    }
};


//{ Driver Code Starts.

void printList(struct Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

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

        struct Node* head = new Node(arr[0]);
        struct Node* tail = head;

        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }

        Solution ob;
        vector<Node*> result = ob.alternatingSplitList(head);
        printList(result[0]);
        printList(result[1]);
    }

    return 0;
}

// } Driver Code Ends