//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Structure for the linked list node
struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

// Function to print nodes in a given circular linked list
void printList(struct Node *head) {
    if (head != NULL) {
        struct Node *temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
    } else {
        cout << "empty" << endl;
    }
    cout << endl;
}


// } Driver Code Ends
class Solution {
  public:
    
    Node* reverse(Node* head) {
    if (head == nullptr || head->next == head) return head;  

    unordered_map<Node*, int> mp;
    vector<int> ans;

    Node* temp = head;

   
    while (temp != nullptr && !mp.count(temp)) {
        ans.push_back(temp->data);  
        mp[temp]++;       
        temp = temp->next;          
        if (temp == head) break;    
    }

    // Reverse the vector `ans`
    int i = 0;
    int j = ans.size() - 1;
    while (i < j) {
        swap(ans[i], ans[j]);
        i++;
        j--;
    }

    
    Node* p = new Node(-1); 
    Node* q = p;
    
    for (auto tt : ans) {
        p->next = new Node(tt);  
        p = p->next;
    }
    
    p->next = q->next;  
    return q->next;
}


   Node* deleteNode(Node* head, int key) {
    if (head == nullptr) return nullptr;  // If the list is empty

    unordered_map<Node*, int> mp;
    vector<int> ans;
    Node* temp = head;
    bool ok = false;

    // Traverse the circular linked list and collect values except the node with the key
    while (!mp.count(temp)) {
        if (temp->data == key && ok == false) {
            ok = true;    // Mark that we found the key and will skip this node
            mp[temp]++;   // Mark the node as visited
            temp = temp->next;  // Move to the next node and skip this one
           // if (temp == head) break;  // Stop if we come back to the head (circular list)
            continue;
        }

        ans.push_back(temp->data);  // Collect node data if it's not the key
        mp[temp]++;  // Mark the node as visited
        temp = temp->next;  // Move to the next node
        if (temp == head) break;  // Stop if we come back to the head (circular list)
    }

    // If the key doesn't exist or we remove all instances of it, return original head
    if (ans.size() == mp.size()) return head;

    // Rebuild the circular linked list without the node with the given key
    Node* p = new Node(-1);  // Dummy node to simplify list construction
    Node* q = p;

    for (auto tt : ans) {
        p->next = new Node(tt);  // Create new nodes with data from the vector
        p = p->next;
    }

    p->next = q->next;  // Make the list circular again by linking the last node to the new head

    return q->next;  // Return the new head of the list
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

        // Reading input into a vector
        while (ss >> number) {
            arr.push_back(number);
        }

        int key;
        cin >> key;
        cin.ignore();

        // Creating the circular linked list
        struct Node *head = new Node(arr[0]);
        struct Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        tail->next = head; // Make the list circular

        Solution ob;

        // Delete the node with the given key
        head = ob.deleteNode(head, key);

        // Reverse the circular linked list
        head = ob.reverse(head);

        // Print the modified list
        printList(head);
    }
    return 0;
}

// } Driver Code Ends