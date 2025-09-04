#include <iostream>
using namespace std;

class twoStacks {
    int* arr;
    int top1;
    int top2;
    int size;

public:
    // Default constructor with default size = 100
    twoStacks() {
        size = 100;
        arr = new int[size];
        top1 = -1;
        top2 = size;
    }

    // Parameterized constructor if user wants custom size
    twoStacks(int s) {
        size = s;
        arr = new int[size];
        top1 = -1;
        top2 = size;
    }

    // Push into stack1
    void push1(int x) {
        if (top2 - top1 > 1) {
            top1++;
            arr[top1] = x;
        } else {
            cout << "Stack Overflow in stack1\n";
        }
    }

    // Push into stack2
    void push2(int x) {
        if (top2 - top1 > 1) {
            top2--;
            arr[top2] = x;
        } else {
            cout << "Stack Overflow in stack2\n";
        }
    }

    // Pop from stack1
    int pop1() {
        if (top1 >= 0) {
            int ans = arr[top1];
            top1--;
            return ans;
        } else {
            return -1; // Stack underflow
        }
    }

    // Pop from stack2
    int pop2() {
        if (top2 < size) {
            int ans = arr[top2];
            top2++;
            return ans;
        } else {
            return -1; // Stack underflow
        }
    }

    // Destructor to free memory
    ~twoStacks() {
        delete[] arr;
    }
};

// Driver code to test the class
int main() {
    twoStacks ts; // uses default size of 100

    // Push elements into both stacks
    ts.push1(10);
    ts.push1(20);
    ts.push2(30);
    ts.push2(40);

    // Pop elements from both stacks
    cout << "Popped from stack1: " << ts.pop1() << endl; // 20
    cout << "Popped from stack2: " << ts.pop2() << endl; // 40
    cout << "Popped from stack1: " << ts.pop1() << endl; // 10
    cout << "Popped from stack2: " << ts.pop2() << endl; // 30

    // Trying to pop from empty stacks
    cout << "Popped from stack1: " << ts.pop1() << endl; // -1
    cout << "Popped from stack2: " << ts.pop2() << endl; // -1

    return 0;
}
