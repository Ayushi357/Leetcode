class Solution {
public:
    bool isValid(string s) {
        // We always start with an openning bracket, can't start with closing bracket
        // we can add as many openning as we want, until we have the same amount of closing ones
        // use a stack, and we will be popping from the top
        // Time: O(n), Space: O(n) (As we are using a stack)
        // We can use a hash map to match the openning with the closing parantheses

        stack<char> st;
        for(char c : s) {
            if(c == '(' || c == '[' || c == '{') {
                st.push(c);
            }
            else {
                if(st.empty() || 
                (c == ')' && st.top() != '(') || 
                (c == '}' && st.top() != '{') ||
                (c == ']' && st.top() != '[')
                ) return false;
            st.pop();
            }
        }
        return st.empty();
    }
};