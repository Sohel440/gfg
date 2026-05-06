#include <bits/stdc++.h>
using namespace std;

class Clist
{
public:
    int data;
    Clist *next;
    // Clist *prev;

    Clist(int data){
        this->data = data;
        this->next =NULL;
        // this->prev =NULL;
    }

     Clist* InsertAtHead(Clist * &tail , int data){
        Clist* newData = new Clist(data);
        if(tail == NULL){
            newData->next = newData;
            tail = newData;;
            return tail;
        }

        
        newData->next = tail->next;
        tail->next = newData;
        //tail = newData;
        return tail;
    }

     Clist* InsertAtTail(Clist * &tail , int data){
        Clist* newData = new Clist(data);
        if(tail == NULL){
            newData->next = newData;
            tail = newData;;
            return tail;
        }

        
        newData->next = tail->next;
        tail->next = newData;
        tail = newData;
        return tail;
    }
    void deletePos(Clist *&tail , int p){
        int count =1;
        Clist * temp = tail;
        while(count < p){
            temp= temp->next;
            count++;
        }
        Clist*t = temp->next;

        temp->next = t->next;
        t->next=NULL;
        delete t;

    }
    void Print(Clist * tail){
        Clist*temp = tail;
        do{
            cout << tail->data << " ";;
            tail = tail->next;
        }while(tail != temp);
        cout << endl;
    }

};

int main()
{

    //cout << "A data: "<< a->data<< endl;
    Clist *tail  = NULL;
    tail = tail->InsertAtHead(tail, 3);
    tail = tail->InsertAtHead(tail , 12);
    tail = tail->InsertAtHead(tail , 15);
    tail = tail->InsertAtHead(tail , 17);
    tail = tail->InsertAtHead(tail , 13);
    tail = tail->InsertAtHead(tail , 11);
    tail = tail->InsertAtHead(tail , 19);
    tail = tail->InsertAtHead(tail , 89);
    tail = tail->InsertAtTail(tail , 80);
    

    tail->Print(tail);
    tail->deletePos(tail, 3);
        tail->Print(tail);


    return 0;
}