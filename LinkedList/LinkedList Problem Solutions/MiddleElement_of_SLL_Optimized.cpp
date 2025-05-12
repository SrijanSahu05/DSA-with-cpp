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

//Optimized logic to get middle element of a single linked list.
Node* getmiddle_of_SLL(Node* &head){

    if(head == NULL || head->next == NULL)
        return head;
    
    if(head->next->next == NULL)
        return head->next;

    Node* slow = head; //it travers n/2 times when fast finishes the traversing.
    Node* fast = head->next; // it travers n times.

    while(fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
        }
        slow = slow->next;
    }

    return slow;
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

    //printing the linked list.
    cout<<"Linked List: ";
    print(head);

    //Middle of SLL.
    cout<<"Middle of a Linked List is: ";
    Node* ans = getmiddle_of_SLL(head);
    cout<<ans->data<<endl;

    return 0;
}