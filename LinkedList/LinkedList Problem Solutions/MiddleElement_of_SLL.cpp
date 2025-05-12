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

//Insert the node of SLL.
void insertAtEnd(Node* &head, Node* &tail, int d){
    
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

//Print the node of SLL.
void print(Node* &head){
    Node* temp = head;

    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node* middle_of_SLL(Node* head){
    int len = 0;
    Node* temp = head;

    while(temp != NULL){
        len++;
        temp = temp->next;
    }

    int mid = len/2;
    
    int cnt = 0;
    while(cnt<mid){
        cnt++;
        head = head->next;
    }

    return head;
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;

    //inserting the node in SLL.

    insertAtEnd(head,tail,11);
    insertAtEnd(head,tail,28);
    insertAtEnd(head,tail,35);
    insertAtEnd(head,tail,4);
    insertAtEnd(head,tail,52);
    insertAtEnd(head,tail,15);
    insertAtEnd(head,tail,32);
    insertAtEnd(head,tail,5);
    insertAtEnd(head,tail,50);
    insertAtEnd(head,tail,22);
    insertAtEnd(head,tail,54);
    insertAtEnd(head,tail,85);

    //printing the linked list.
    cout<<"Linked List: ";
    print(head);

    //Middle of SLL.
    cout<<"Middle of a Linked List is: ";
    Node* ans = middle_of_SLL(head);
    cout<<ans->data<<endl;

    return 0;
}