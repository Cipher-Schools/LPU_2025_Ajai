#include <bits/stdc++.h>
using namespace std;

int precedence(char c) {
    if(c == '^') return 3;
    if(c == '*' || c == '/') return 2;
    if(c == '+' || c == '-') return 1;
    return 0;
}

string infixToPostfix(string s) {
    stack<char> st;
    string result = "";

    for(char c : s) {

        if(isalnum(c)) result += c;

        else if(c == '(') st.push(c);

        else if(c == ')') {
            while(!st.empty() && st.top() != '(') {
                result += st.top();
                st.pop();
            }
            st.pop();
        }

        else {
            while(!st.empty() && precedence(st.top()) >= precedence(c)) {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while(!st.empty()) {
        result += st.top();
        st.pop();
    }

    return result;
}

string infixToPrefix(string s) {
    // 1. Reverse
    reverse(s.begin(), s.end());

    // 2. Swap ( and )
    for(char &c : s) {
        if(c == '(') c = ')';
        else if(c == ')') c = '(';
    }

    // 3. Convert to postfix
    string postfix = infixToPostfix(s);

    // 4. Reverse postfix → prefix
    reverse(postfix.begin(), postfix.end());
    return postfix;
}

int main() {
    string exp = "(A-B/C)*(A/K-L)";
    cout << "Prefix: " << infixToPrefix(exp);
}


