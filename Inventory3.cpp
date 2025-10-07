#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Browser {
    stack<string> history; // stack to store pages in reverse
    vector<string> order;  // to keep order for history display

public:
    // Visit a new page
    void visitPage(const string& page) {
        history.push(page);
        order.push_back(page);
        cout << "Visited: " << page << endl;
    }

    // Go back to previous page
    void goBack() {
        if (history.empty()) {
            cout << "No pages in history." << endl;
            return;
        }
        string lastPage = history.top();
        history.pop();
        order.pop_back();

        cout << "Going back from: " << lastPage << endl;
        if (!history.empty()) {
            cout << "Current page: " << history.top() << endl;
        } else {
            cout << "No pages left in history." << endl;
        }
    }

    // Show browsing history
    void showHistory() {
        if (order.empty()) {
            cout << "History is empty." << endl;
            return;
        }
        cout << "History: ";
        for (size_t i = 0; i < order.size(); i++) {
            cout << order[i];
            if (i != order.size() - 1) cout << " -> ";
        }
        cout << endl;
    }
};

int main() {
    Browser browser;
    int choice;
    string page;

    while (true) {
        cout << "\n1. Visit Page" << endl;
        cout << "2. Back" << endl;
        cout << "3. Show History" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter page name: ";
                cin >> page;
                browser.visitPage(page);
                break;
            case 2:
                browser.goBack();
                break;
            case 3:
                browser.showHistory();
                break;
            case 4:
                cout << "Exiting browser simulation." << endl;
                return 0;
            default:
                cout << "Invalid choice." << endl;
        }
    }
}
