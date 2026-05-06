#include <bits/stdc++.h>
using namespace std;

class List
{
public:
    int data;
    List *next;

    List(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    ~List(){
        int val = this->data;
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
        cout << " Memory freed!"<< endl;
    }
    void insertHead(List *&head, int d)
    {
        List *temp = new List(d);
        temp->next = head;
        head = temp;
    }
    void insertTail(List *&head, int d)
    {

        List *temp = new List(d);
        List *t = head;
        while (head->next)
        {
            head = t->next;
        }
        head->next = temp;
        head = t;
    }
    void insertAtmiddle(List *&head, int p, int d)
    {
        List *t = head;
        int count = 1;
        while (head && count != p - 1)
        {
            count++;
            head = head->next;
        }
        List *temp = new List(d);
        List *nw = head->next;
        head->next = temp;
        temp->next = nw;
        head = t;
    }
    void deletionAtPos(List *&head, int pos)
    {
        if(pos == 1){
            List *d= head;
            head = head->next;
            d->next = NULL;
            delete d;
            return;
        }
        List *t = head;
        int count = 1;

        while (t && count < pos - 1)
        {
            t = t->next;
            count++;
        }

        List *d = t->next;
        t->next = d->next;
        d->next= NULL;
        delete d;
    }
    void Print(List *&head)
    {
        List *t = head;

        while (t != NULL)
        {
            cout << t->data << " ";
            t = t->next;
        }
        cout << endl;
    }
};

int main()
{

    List *a = new List(10);
    a->insertHead(a, 20);
    a->insertTail(a, 30);
    a->insertAtmiddle(a, 2, 13);
    a->insertAtmiddle(a, 4, 70);

    // vector<List> ans ;
    // cout << a->data<< endl;
    a->Print(a);

    a->deletionAtPos(a, 1);
    a->Print(a);
    return 0;
}