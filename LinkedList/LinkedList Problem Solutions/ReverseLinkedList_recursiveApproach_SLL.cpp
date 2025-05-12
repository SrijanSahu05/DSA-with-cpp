/*Recursive approach or reversing the linked list.*/

#include<iostream>
using namespace std;

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

//Reversing the linked list using recursive approach.
Node* ReverseLinkedList_recursively(Node* head){
    //base case
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* sm_Head = ReverseLinkedList_recursively(head->next);

    head->next->next = head;
    head->next = NULL;

    return sm_Head;
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
    
    head = ReverseLinkedList_recursively(head);

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