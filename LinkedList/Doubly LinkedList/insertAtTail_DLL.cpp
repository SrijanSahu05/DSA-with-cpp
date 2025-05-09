#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* prev;
        Node* next;
    
    //constructor
    Node(int d){
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
};


//inserting node in doubly linked list.
void insetAtTail(Node* &tail, int d){
    Node* temp = new Node(d);

    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

//Traversing doubly linked list
void print(Node* &head){
    Node* temp = head;

    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
    Node* node = new Node(1);
    Node* head = node;
    Node* tail = node;

    print(head);

    insetAtTail(tail, 2);
    print(head);
    insetAtTail(tail, 3);
    print(head);
    insetAtTail(tail, 4);
    print(head);
    insetAtTail(tail, 5);
    print(head);

    return 0;
}