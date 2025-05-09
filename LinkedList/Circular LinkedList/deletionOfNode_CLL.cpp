#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

    //constructor
    Node(int d){
        this->data = d;
        this->next = NULL;
    }

    //distructor
    ~Node(){
        int val = this->data;

        if(this->next != NULL){
            delete next;
            next = NULL;
        }
        cout<<"Memory is free for node with data: "<<val<<endl;
    }
};

//Node insertion in singly circular linked list.
void insertNode(Node* &tail, int element, int d){
    //empty list
    if(tail == NULL){
        Node* newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
    }
    else{
        //non-empty list

        Node* curr = tail;

        while(curr->data != element){
            curr = curr->next;
        }

        Node* temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;  
    }
}

//deletion of node by value in singly circular linked list.
void deleteNode(Node* &tail, int value){
    //empty list
    if(tail == NULL){
        cout<<"List is empty, please check again."<<endl;
        return;
    }
    else{
        //non-empty list
        Node* prev = tail;
        Node* curr = prev->next;

        while(curr->data != value){
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;

        //1 node linked list
        if(curr == prev){
            tail = NULL;
        } // >=2 Node linked list.
        else if(tail == curr){
            tail = prev;
        }
        curr->next = NULL;
        delete curr;
    }
}

//Printing the node of singly circular linked list.
void print(Node* &tail){
    Node* temp = tail;

    if(tail == NULL){
        cout<<"List is Empty."<<endl;
        return;
    }

    do{
        cout<<tail->data<<" ";
        tail = tail->next;
    }while(tail != temp);

    cout<<endl;
}

int main(){
    Node* tail = NULL;

    //inserting the node.

    insertNode(tail,5,3);
    print(tail);

   insertNode(tail,3,5);
    print(tail);

    /*insertNode(tail,5,7);
    print(tail);

    insertNode(tail,7,9);
    print(tail);

    insertNode(tail,5,6);
    print(tail);

    insertNode(tail,9,10);
    print(tail);

    insertNode(tail,3,4);
    print(tail);*/

    //deleting the node.

    /*deleteNode(tail,3);
    print(tail);

    deleteNode(tail,10);
    print(tail);

    deleteNode(tail,5);
    print(tail);*/

    deleteNode(tail,3);
    print(tail);

    return 0;
}