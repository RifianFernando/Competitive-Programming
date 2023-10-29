#include<bits/stdc++.h>

using namespace std;

bool isBalanced(const string& s) {
    vector<char> parenthesesStack;
    unordered_map<char, char> parenthesesMap = {
        {')', '('},
        {']', '['}
        // Add more mappings if needed
        // (())[]([)] -> The output should be yes but the output is no
    };

    if (s.size() % 2 == 1) return false;  // Odd length strings are not balanced
    for (char c : s) {
        if (c == '(' || c == '[') {
            // Push opening parentheses onto the stack
            // cout << "setelah divalidasi: ";
            // cout << c << endl;
            parenthesesStack.push_back(c);
        } else if (c == ')' || c == ']') {
            // cout << "setelah divalidasi: c == ')' || c == ']' || c == '}': ";
            // cout << c << endl;
            auto it = find(parenthesesStack.begin(), parenthesesStack.end(), parenthesesMap.at(c));

            if (it == parenthesesStack.end()) {
                return false;// Unmatched closing parentheses
            }
            // for (auto it = parenthesesStack.rbegin(); it != parenthesesStack.rend(); ++it) {
            //     cout << *it << " ";
            // }
            // cout << endl;
            parenthesesStack.erase(it);  // Matched, pop the opening parentheses
        }
    }

    return parenthesesStack.empty();  // it will return true if the stack is empty
}

bool isBalanced2(const string& s) {
    map<char, int> parenthesesMap = {
        {')', 0},
        {']', 0},
        {'(', 0},
        {'[', 0}
        // Add more mappings if needed
    };
    return true;
}

int main() {
    int n; cin >> n;cin.ignore();

    for (int i = 0; i < n; i++) {
        string inputString; // Ignore the newline character before reading the string
        getline(cin, inputString);
        
        if (inputString.size() == 0) {
            cout << "Yes" << endl;
            continue;
        } else{
            if (isBalanced(inputString)) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }

    return 0;
}
