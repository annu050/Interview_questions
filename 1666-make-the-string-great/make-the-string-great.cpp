class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        
        for (char c : s) {
            // Check if the stack is not empty and c forms a "bad" pair with the top of the stack
            if (!st.empty() && abs(c - st.top()) == 32) {
                st.pop(); // Pop the character from the stack
            } else {
                st.push(c); 
            }
        }
        
        string result = "";
        while (!st.empty()) {
            result = st.top() + result;
            st.pop();
        }
        
        return result;
    }
};