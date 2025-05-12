/*Reverse a node of Doubly linked list.*/

#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* prev;
        Node* next;

    Node(int d){
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
};

//insert node in doubly linked list.
void insertAtEnd(Node* &head, Node* &tail, int d){
    
    if(head == NULL){
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else{
        Node* temp = new Node(d);

        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

//prints the node of doubly linked list.
void print(Node* &head){
    Node* temp = head;

    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

//revers the node of doubly linked list.
void reverse_DLL(Node* &tail){
    Node* temp = tail;

    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->prev;
    }
    cout<<endl;
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;

    //inserting node in doubly linked list.
    insertAtEnd(head,tail,10);
    insertAtEnd(head,tail,20);
    insertAtEnd(head,tail,30);
    insertAtEnd(head,tail,40);
    insertAtEnd(head,tail,50);

    cout<<"Doubly Linked List: ";
    print(head);

    cout<<"Reverse of Doubly Linked List: ";
    reverse_DLL(tail);

    return 0;
}