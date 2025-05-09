#include<iostream>
using namespace std;


//Singly LinkedList Node created.
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

//Insert node at the end of linked list.
void InsertAtEnd(Node* &tail, int d){

    //new node create
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = temp;
}

//Printing the linked list.
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

    Node* head = node;
    Node* tail = node;

    print(head);

    InsertAtEnd(tail, 20);

    print(head);

    InsertAtEnd(tail, 30);
 
    print(head);

    return 0;
}