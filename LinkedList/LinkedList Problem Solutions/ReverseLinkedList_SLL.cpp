/*Iterative approach of reversing the linked list.*/

#include<iostream>
using namespace std;

//Linked List class to create a node.
class Node{
    public:
        int data;
        Node* next;
    
    Node(int d){
        this->data = d;
        this->next = NULL;
    }
};


//insert the node in linked list.
void insertNodeAtEnd(Node* &head, Node* &tail, int d){
    if(head == NULL){
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else{
        Node* temp = new Node(d);
        
        tail->next = temp;
        tail = temp;
    }
}


//Prints the Linked list node.
void print(Node* &head){
    Node* temp = head;

    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}


//Reverse the linked list node.
Node* ReverseLinkedList(Node* &head){

    //Check if linked list is empty or only 1 node is present.
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* prev = NULL;
    Node* curr = head;

    while(curr != NULL){
        Node* forward = curr->next;
        curr->next = prev;

        prev = curr;
        curr = forward;
    }

    return prev;
}


int main(){
    Node* head = NULL;
    Node* tail = NULL;

    //inserting the node in linkedlist.
    insertNodeAtEnd(head,tail,1);
    insertNodeAtEnd(head,tail,2);
    insertNodeAtEnd(head,tail,3);
    insertNodeAtEnd(head,tail,4);
    insertNodeAtEnd(head,tail,5);

    //printing the node of linkedlist.
    cout<<"Linked List: ";
    print(head);
    
    head = ReverseLinkedList(head);

    //printing the reverse node of linkedlist.
    cout<<"Reverse Linked List: ";
    print(head);

    return 0;
}

/*
NOTE:-
    Time complexity : O(n)
    Sapce complexity : O(n)
*/