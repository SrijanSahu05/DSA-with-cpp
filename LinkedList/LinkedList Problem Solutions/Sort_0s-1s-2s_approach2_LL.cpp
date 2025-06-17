//When data replacement is not allowed, we can use a three-pointer approach to sort the linked list in one pass.

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
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;

    Node* curr = head;

    //Create three separate lists for 0s, 1s, and 2s
    while(curr != NULL){
        int val = curr->data;

        if(val == 0){
            insertAtEnd(zeroHead, zeroTail, val);
        }
        else if(val == 1){
            insertAtEnd(oneHead, oneTail, val);
        }
        else if(val == 2){
            insertAtEnd(twoHead, twoTail, val);
        }

        curr = curr->next;
    }

    //Merge the three lists
    if(oneHead->next != NULL){
        zeroTail->next = oneHead->next;
    }
    else{
        zeroTail->next = twoHead->next;
    }

    oneTail->next = twoHead->next;
    twoTail->next = NULL;

    head = zeroHead->next;

    //delete the dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;
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

/* 
Time complexity
    - O(n), where n is the number of nodes in the linked list.
Space complexity
    - O(1) if we ignore the space used by the new nodes for 0s, 1s, and 2s.
    - O(n) if we consider the space used by the new nodes.
*/