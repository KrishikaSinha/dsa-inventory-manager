#include <iostream>
#include <stack>
using namespace std;

// Reverse a string
string reverseString(const string& input) {
    stack<char> s;
    for (char ch : input) s.push(ch);
    string reversed;
    while (!s.empty()) {
        reversed += s.top();
        s.pop();
    }
    return reversed;
}

// Check balanced parentheses
bool isBalanced(const string& expr) {
    stack<char> s;
    for (char ch : expr) {
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.empty()) return false;
            char top = s.top();
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;
            }
            s.pop();
        }
    }
    return s.empty();
}

// Undo operation simulation
string simulateUndo(const string& input, int undoCount) {
    stack<char> s;
    for (char ch : input) s.push(ch);
    while (undoCount-- && !s.empty()) s.pop();
    string result;
    while (!s.empty()) {
        result = s.top() + result;
        s.pop();
    }
    return result;
}

int main() {
    // Reverse
    string str = "hello";
    cout << "Reversed: " << reverseString(str) << endl;

    // Balanced parentheses
    string expr = "({{[]}})";
    cout << "Balanced: " << (isBalanced(expr) ? "Yes" : "No") << endl;

    // Undo simulation
    string text = "he1";
    int undoSteps = 1;
    cout << "After undo: " << simulateUndo(text, undoSteps) << endl;

    return 0;
}
