#include<bits/stdc++.h>

using namespace std;

bool isBalanced(const string& s) {
    vector<char> parenthesesStack;
    unordered_map<char, char> parenthesesMap = {
        {')', '('},
        {']', '['}
    };

    if (s.size() % 2 == 1) return false;  // Odd length strings are not balanced
    for (char c : s) {
        if (c == '(' || c == '[') {
            parenthesesStack.push_back(c);
        } else if (c == ')' || c == ']') {
            auto it = find(parenthesesStack.begin(), parenthesesStack.end(), parenthesesMap.at(c));
            if (it == parenthesesStack.end()) {
                return false; // Unmatched closing parentheses
            }
            parenthesesStack.erase(it, it + 1);  // Matched, pop the opening parentheses
        }
    }

    return parenthesesStack.empty();
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
