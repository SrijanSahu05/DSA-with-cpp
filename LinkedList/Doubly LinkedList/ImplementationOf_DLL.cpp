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

//traversing a linked list
void print(Node* head){
    Node* temp = head;

    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

//Length of linked list
int getLength(Node* head){
    int len = 0;
    Node* temp = head;

    while(temp != NULL){
        len++;
        temp = temp -> next;
    }

    return len;
}

int main(){
    Node* node = new Node(10);
    Node* head = node;

    print(head);
    cout<<"Length of linked list: "<<getLength(head)<<endl;

    return 0;
}