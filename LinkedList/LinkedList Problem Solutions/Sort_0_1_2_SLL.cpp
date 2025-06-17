#include<bits/stdc++.h>
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
        Node* newNode = new Node(d);
        head = newNode;
        tail = newNode;
    }
    else{
        Node* temp = new Node(d);
        tail->next = temp;
        tail = temp;
    }
}

void sortList(Node* &head){
    int zeroCount = 0, oneCount = 0, twoCount = 0;
    Node* temp = head;

    while(temp != NULL){
        if(temp->data == 0){
            zeroCount++;
        }
        else if(temp->data == 1){
            oneCount++;
        }
        else if(temp->data == 2){
            twoCount++;
        }

        temp = temp->next;
    }

    temp = head;
    
    while(temp != NULL){
        if(zeroCount != 0){
            temp->data = 0;
            zeroCount--;
        }
        else if(oneCount != 0){
            temp->data = 1;
            oneCount--;
        }
        else if(twoCount != 0){
            temp->data = 2;
            twoCount--;
        }

        temp = temp->next;
    }
}


void printList(Node* head){
    Node* temp = head;

    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;

    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the elements (0, 1, or 2): ";

    for(int i = 0; i<n; i++){
        int x;
        cin>>x;
        insertAtEnd(head, tail, x);
    }

    cout<<"The linked list is: ";
    printList(head);
    cout<<endl;

    sortList(head);

    cout<<"Sorted linked list is: ";
    printList(head);
    cout<<endl;

    return 0;
}