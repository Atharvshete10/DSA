#include<iostream>
using namespace std;

struct node{
    int data;
    node *next , *prev;
};

class DCLL{
    node *head;
    public:
    DCLL(){
        head = NULL;
    }
    void addFront(int da){
        node *nn = new node;
        nn->data = da;
        nn->next = NULL;
        nn->prev = NULL;

        if(!head){
            head = nn;
            head->next = head;
            head->prev = head;
            return;
        }else{
            nn->next = head;
            nn->prev = head->prev;
            head->prev->next = nn;
            head->prev = nn;
            head = nn;
        }
    }

    
    void addEnd(int da){
        node *nn = new node;
        nn->data = da;
        nn->next = NULL;
        nn->prev = NULL;

        if(!head){
            head = nn;
            head->next = head;
            head->prev = head;
            return;
        }else{
            nn->next = head;
            nn->prev = head->prev;
            head->prev->next = nn;
            head->prev = nn;
        }
    }
    void deletenode(int key){
        //If list is empty
        if(!head){  
            cout<<"List is empty."<<endl;
            return;
        }
        // If only one element in the list
        if(head->next == head && head->data == key){
            delete head;
            head = NULL;
            return;
        }
        // Deleting head of the list
        node *ptr = head;
        if(key == head->data){
            head->prev->next = ptr->next;
            ptr->next->prev = head->prev;
            head = ptr->next;
            delete ptr;
            return;
        }
        // Deleting middle element of the list
        node *p = head->next;
        while(p != head){
            if(p->data == key){
                p->prev->next = p->next;
                p->next->prev = p->prev;
                delete p;
                return;
            }
            p = p->next;
        }
        cout<<"key "<<key<<" not found in the list."<<endl;
    }
    void displayReverse() {
        if (!head) {
            cout << "List is empty\n";
            return;
        }
        node *temp = head->prev;   
        do {
            cout << temp->data << "\t";
            temp = temp->prev;
        } while (temp != head->prev);
        cout << endl;
    }

    void display(){
        if(!head){
            return;
        }
        node *p = head;
        do{
            cout<<p->data<<"\t";
            p = p->next;
        }
        while(p != head);
        cout<<endl;
    }
    void length(){
        if(!head){
            cout<<"Empty list."<<endl;
            return;
        }
        int count = 0;
        node *ptr = head;
        do{
            count++;
            ptr = ptr->next;
        }while(ptr != head);
        cout<<"length of list is:"<<count;
    }
};

int main(){
    DCLL d;
    d.length();
    d.addEnd(1);
    d.addEnd(2);
    d.addEnd(3);
    d.addEnd(4);
    d.addEnd(5);
    d.addFront(6);
    d.addFront(7);
    d.addFront(8);
    d.addFront(9);
    d.deletenode(1);
    d.display();
    d.displayReverse();
    d.length();
    return 0;
}