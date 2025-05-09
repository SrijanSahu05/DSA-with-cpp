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

void InsertAtHead(Node* &head, int d){

    //new node create
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}

void print(Node* &head){
    Node* temp = head;

    while(temp != NULL){
        cout<< temp -> data << " ";
        temp = temp -> next;
    }
    cout<<endl;
}

int main(){
    //New node is created with a new value.
    Node* node = new Node(10);  
    
    //head pointed to node
    Node* head = node;
    print(head);

    InsertAtHead(head, 12);

    print(head);

    return 0;
}