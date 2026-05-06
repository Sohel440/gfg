#include <bits/stdc++.h>
using namespace std;

class Dlist
{
public:
    int data;
    Dlist *next;
    Dlist *prev;

    Dlist(int data){
        this->data = data;
        this->next =NULL;
        this->prev =NULL;
    }

    ~Dlist(){
        int val = this->data;
        if(this->next != NULL || this->prev!=NULL){
            delete next;;
            delete prev;
            this->next = NULL;
            this->prev = NULL;

        }
        cout<< "Memory free !"<< endl;

        
    }
    void InsertAtHead(Dlist* &head  , int d){
        Dlist *temp = new Dlist(d);
        temp->next = head;
        if(head != NULL){
        head->prev = temp;
    }
        head = temp;

    }
    void InsertAtPos(Dlist* &head , int pos , int d){
        Dlist* newData = new Dlist(d);
        if(pos ==1){
            InsertAtHead(head , d);
            return;
        }
        Dlist* c = head;
        Dlist* p = NULL;
        int count =1;
        while(c && count < pos){
            p = c;
            c = c->next;
            count++;
        } 
        if(c==NULL){
            p->next =newData;
            newData->prev=p;
            return;
        }
        newData->next = c;
        newData ->prev = p;
        c->prev = newData;
        p->next = newData;


        // 20 30 40 50 60

    }
    void InsertAtTails(Dlist *&head , int d){

        Dlist* newData = new Dlist(d);
        Dlist* t = head;
        while (t->next != NULL)
        {
            t=t->next;
        }
        
        t->next = newData;
        newData->prev =t;
        
    }
    void Print(Dlist* a){
        while(a){
            cout << a->data << " ";
            a = a->next;
        }
        cout << endl;
    }

    void deleteAtPos(Dlist *&head , int pos){
        Dlist * c = head;
        Dlist * p = NULL;
        int count =1;
        if(pos==1){
            Dlist * temp = head;
        

            head = head->next;
            temp->next = NULL;

            delete temp;
            return;
        }

        while (c && count < pos)
        {
            p = c;
            c = c->next;
            count++;
        }
        if( c->next == NULL){
            cout << "Hello"<< endl;
            p->next = NULL;
            c->prev = NULL;
            delete c;
            return;
        }
        p->next = c->next;
        c->next->prev = p;
        c->next=NULL;
        c->prev=NULL;
        delete c;
        
    }
};

int main()
{
    Dlist *a = new Dlist(20);
   // a->Print(a);
    a->InsertAtHead(a, 30);
    a->InsertAtHead(a, 40);
    a->InsertAtHead(a, 50);
    a->Print(a);

    a->InsertAtPos(a, 5 , 35);
    a->InsertAtTails(a, 5);

    
    a->Print(a);
    a->deleteAtPos(a , 6);
    a->Print(a);

    //cout << "A data: "<< a->data<< endl;

    return 0;
}