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

        // 1. Operand → directly to output
        if(isalnum(c)) {
            result += c;
        }

        // 2. Opening bracket → push to stack
        else if(c == '(') {
            st.push(c);
        }

        // 3. Closing bracket → pop until '('
        else if(c == ')') {
            while(!st.empty() && st.top() != '(') {
                result += st.top();
                st.pop();
            }
            st.pop(); // remove '('
        }

        // 4. Operator
        else { 
            while(!st.empty() && precedence(st.top()) >= precedence(c)) {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    // 5. Pop remaining operators
    while(!st.empty()) {
        result += st.top();
        st.pop();
    }

    return result;
}

int main() {
    string exp = "(A+B)*C-D";
    cout << "Postfix: " << infixToPostfix(exp);
}
