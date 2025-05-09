#include<iostream>
using namespace std;

//Singly LinkedList Node creation.
class Node{
    public:
        int data;
        Node* next;
    //constructor
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

//Insert node at the start of linked list.
void InsertAtHead(Node* &head, int d){

    //new node create
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}

//Insert node at the end of linked list.
void InsertAtEnd(Node* &tail, int d){

    //new node create
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = temp;
}

//Insert node at position of linked list.
void InsertAtPosition(Node* &head,Node* &tail, int position, int d){

    //insert at start.
    if(position == 1){
        InsertAtHead(head,d);
        return;
    }

    Node* temp = head;
    int cnt = 1;

    while(cnt < position - 1){
        temp = temp -> next;
        cnt++;
    }

    //insert at last position.
    if(temp->next == NULL){
        InsertAtEnd(tail,d);
        return;
    }

    //creating a node for d
    Node* nodeToInsert = new Node(d);

    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert;
}

//Printing the singly linkedlist.
void print(Node* &head){
    Node* temp = head;

    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
    //New node is created with a new value.
    Node* node = new Node(10);  

    Node* head = node;
    Node* tail = node;

    print(head);

    InsertAtEnd(tail, 20);
    print(head);

    InsertAtEnd(tail, 30);
    print(head);

    InsertAtPosition(head,tail, 4, 40);
    print(head);

    //verify head and tail.
    cout<<"Head: "<<head->data<<endl;
    cout<<"Tail: "<<tail->data<<endl;

    return 0;
}