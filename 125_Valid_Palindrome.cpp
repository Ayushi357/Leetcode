class Solution {
public:
    bool isPalindrome(string s) {
        // Solution 1: convert everything to lowercase and reverse the string and check with the original
        // we used extra memory and used built-in function
        // Soultion 2: increment left pointer and decrement right pointer and compare
        // ignore everything which is not alnum: can use ascii values
        // while l != alnum l++
        // Time: O(n), Space: O(1)
        int i = 0;
        int j = s.size() - 1;
        while(i < j) {
            while(!isalnum(s[i]) && i < j) {
                i++;
            }
            while(!isalnum(s[j]) && i < j) {
                j--;
            }
            if(tolower(s[i]) != tolower(s[j])) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};