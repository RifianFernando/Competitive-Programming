#include<bits/stdc++.h>

using namespace std;

bool isBalanced(const string& s) {
    stack<char> parenthesesStack;
    unordered_map<char, char> parenthesesMap = {
        {')', '('},
        {']', '['}
        // Add more mappings if needed
    };

    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            // Push opening parentheses onto the stack
            parenthesesStack.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            // Check for matching opening parentheses on the stack
            if (parenthesesStack.empty() || parenthesesStack.top() != parenthesesMap[c]) {
                return false;  // Unmatched closing parentheses
            }
            parenthesesStack.pop();  // Matched, pop the opening parentheses
        }
    }

    return parenthesesStack.empty();  // Stack should be empty for balanced parentheses
}

int main() {
    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        string inputString;
        cin >> inputString;
        
        if (isBalanced(inputString)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}
