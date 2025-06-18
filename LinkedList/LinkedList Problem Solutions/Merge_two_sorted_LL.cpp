// This program merges two sorted linked lists into a single sorted linked list.
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

// Function to insert a new node at the end of the linked list
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

// Function to print the linked list
void printList(Node* head){
    Node* temp = head;

    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

// Function to check if the linked list is sorted
bool isListSorted(Node* head){
    if(head == NULL || head->next == NULL) return true;

    Node* temp = head;

    while(temp->next != NULL){
        if(temp->data > temp->next->data) return false;
        temp = temp->next;
    }

    return true;
}

// Function to merge two sorted linked lists
Node* solve(Node* &list1, Node* &list2){
    Node* curr1 = list1;
    Node* next1 = curr1->next;
    Node* curr2 = list2;
    Node* next2 = curr2->next;

    while(next1 != NULL && curr2 != NULL){

        if((curr2->data >= curr1->data) && (curr2->data <= next1->data)){
            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;

            curr1 = curr2;
            curr2 = next2;
        }
        else{
            curr1 = next1;
            next1 = next1->next;

            if(next1 == NULL){
                curr1->next = curr2;
                return list1;
            }
        }
    }

    return list1;
}

// Function to merge two sorted linked lists
Node* mergeLists(Node* &list1, Node* &list2){
    if(list1 == NULL) return list2;
    if(list2 == NULL) return list1;

    if(list1->data < list2->data){
        return solve(list1, list2);
    }
    else{
        return solve(list2, list1);
    }
}

int main(){
    Node* list1 = NULL;
    Node* tail1 = NULL;
    Node* list2 = NULL;
    Node* tail2 = NULL;

    cout<<"Note: Enter the elements in sorted order. If you not enter the elements in sorted order you will not get the desired output."<<endl;
    cout<<endl;

    int n1,n2,d;
    
    cout<<"Enter the number of elements in first list: ";
    cin>>n1;

    cout<<"Enter the elements of first list: ";
    while(n1--){
        cin>>d;
        insertAtEnd(list1, tail1, d);
    }

    // Check if the first list is sorted
    if(!isListSorted(list1)){
        cout<<"The first list is not sorted. Please enter the elements in sorted order."<<endl;
        return 0;
    }

    cout<<"Enter the number of elements in second list: ";
    cin>>n2;

    cout<<"Enter the elements of second list: ";
    while(n2--){
        cin>>d;
        insertAtEnd(list2, tail2, d);
    }

    // Check if the second list is sorted
    if(!isListSorted(list2)){
        cout<<"The second list is not sorted. Please enter the elements in sorted order."<<endl;
        return 0;
    }

    // Merge the two sorted linked lists
    Node* mergedList = mergeLists(list1, list2);

    cout<<"The Merged List is: ";
    printList(mergedList);
    cout<<endl;

    return 0;
}