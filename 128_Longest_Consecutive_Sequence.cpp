class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Imagine by drawing a number line
        // Seq 1: 1, 2, 3, 4
        // Another sequence, 1 number 100, same with 200
        // 3 different sequence. How would a human solve it? Look at sequence and count
        // How can we identify what makes a sequence? Start value has no left neighbor
        // Get start of each sequence, figuring out which one doesn't have a left neighbor
        // Taking initial array and converting into set
        // Count how many consecutive number comes after
        // We went through the array and made all the sequence
        // Time: O(n), Space: O(n)

        unordered_set<int> s(nums.begin(), nums.end());
        int longest = 0;
        for(auto &n : s) {
            if(!s.count(n - 1)) {
                int length = 1;
                while(s.count(n + length)) {
                    length++;
                }
                longest = max(longest, length);
            }
        }
        return longest;
    }
};