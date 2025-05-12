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

void print(Node* &head){
    Node* temp = head;

    while(temp != NULL){
        cout<< temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}

//This function calculates the length of a linkedlist.
int lengthOfList(Node* head){
    Node* temp = head;
    int length = 0;
    
    while(temp != NULL){
        length++;
        temp = temp->next;
    }
    
    return length;
}

//This function gives the kth node from the end of linkedlist.
int getKthFromLast(Node *head, int k) {
    int len = lengthOfList(head);
    
    if(k > len) return -1;
    
    int cnt = 1;
    
    while(cnt != (len - k) + 1){
        cnt++;
        head = head->next;
    }
    
    return head->data;
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;

    insertAtEnd(head,tail,20);
    insertAtEnd(head,tail,30);
    insertAtEnd(head,tail,40);
    insertAtEnd(head,tail,45);
    insertAtEnd(head,tail,50);

    print(head);

    cout<<"Head: "<<head->data<<endl;
    cout<<"Tail: "<<tail->data<<endl;

    int k;
    cout<<"Enter the position of the node from the end you want to print: ";
    cin>>k;

    cout<<"The node position "<<k<<" from the end is: "<<getKthFromLast(head,k)<<endl;

    return 0;
}