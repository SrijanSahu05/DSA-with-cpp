#include<iostream>
using namespace std;

//Doubly linked list class
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

//Insert at head function.
void insertAtHead(Node* &head, int d){
    Node* temp = new Node(d);
    
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void print(Node* &head){
    Node* temp = head;

    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
    Node* node = new Node(10);
    Node* head = node;

    insertAtHead(head, 20);
    print(head);

    insertAtHead(head,30);
    print(head);

    insertAtHead(head,40);
    print(head);

    return 0;
}