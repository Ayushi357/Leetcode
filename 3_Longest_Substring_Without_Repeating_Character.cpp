class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // We can keep a set to check for duplicates
        // keep shrinking the window when you see any duplicates, expand when you see unique
        // Time: O(n), Space: O(n)
        unordered_set<char> st;
        int i = 0, j = 0;

        int result = 0;

        while(j < s.size()) {
            if(st.find(s[j]) == st.end()) {
                st.insert(s[j]);
                result = max(result, j - i + 1);
                j++;
            } else {
                st.erase(s[i]);
                i++;
            }
        }
        return result;
    }
};