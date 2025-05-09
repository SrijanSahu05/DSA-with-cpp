#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
    
    //constructor
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }

    //destructor
    ~Node(){
        int value = this->data;
        //memory free
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
        cout<<"Memory is free for node with data: "<<value<<endl;
    }
};

void insert(Node* &tail, int d){
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void deleteNodeAtPosition(Node* &head, int position){
    //deleting first/start node.
    if(position == 1){
        Node* temp = head;
        head = head->next;
        //memory free start node.
        temp->next = NULL;
        delete temp;
    }
    else{
         //deleting any middle node or last node.
         Node* curr = head;
         Node* prev = NULL;

         int cnt = 1;
         while(cnt < position){
            prev = curr;
            curr = curr->next;
            cnt++;
         }
         
         prev->next = curr -> next;
         curr->next = NULL;
         delete curr;
    }
}

void print(Node* &head){
    Node* temp = head;

    while(temp != NULL){
        cout<< temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
    Node* node = new Node(10);

    Node* head = node;
    Node* tail = node;

    insert(tail,20);
    insert(tail,30);
    insert(tail,40);
    insert(tail,45);
    insert(tail,50);

    print(head);

    cout<<"Head: "<<head->data<<endl;
    cout<<"Tail: "<<tail->data<<endl;

    deleteNodeAtPosition(head, 6);
    print(head);

    return 0;
}