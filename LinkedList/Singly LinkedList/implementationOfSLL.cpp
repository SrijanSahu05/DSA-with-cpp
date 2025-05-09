#include<iostream>
using namespace std;

//Singly LinkedList Node creation.
class Node{
    public:
        int data;
        Node* next;

        //constructor
        Node(int data){
            this -> data = data;
            this -> next = NULL;
        }
};

int main(){
    
    Node* node = new Node(10);  //New node is created with a new value.

    cout<<node -> data << endl;
    cout<<node -> next << endl;

    return 0;
}