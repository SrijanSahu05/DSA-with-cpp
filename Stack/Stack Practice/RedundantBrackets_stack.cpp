#include <iostream>
#include <stack>
#include <string>
using namespace std;

int checkRedundancy(string s) {
    stack<char> st;

    for (char ch : s) {
        // Push operators and opening brackets to stack
        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            st.push(ch);
        }
        // When closing bracket is found
        else if (ch == ')') {
            bool isRedundant = true;

            // Check inside brackets
            while (!st.empty() && st.top() != '(') {
                char top = st.top();
                if (top == '+' || top == '-' || top == '*' || top == '/') {
                    isRedundant = false;  // Found an operator
                }
                st.pop();
            }

            if (!st.empty()) st.pop(); // Pop the opening '('

            if (isRedundant) {
                return 1; // Redundant brackets found
            }
        }
    }

    return 0; // No redundancy
}

int main() {
    string expr;
    cout << "Enter expression: ";
    cin >> expr;

    if (checkRedundancy(expr)) {
        cout << "Redundant brackets found.\n";
    } else {
        cout << "No redundant brackets.\n";
    }

    return 0;
}