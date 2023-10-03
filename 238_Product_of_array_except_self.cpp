class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // Keep a prefix and postfix array for all the numbers
        // Time: O(n) Space: O(n)

        // Instead of that we can just store our pre-fix and post-fix in the output array
        // Time: O(n), Space: O(1)

        int n = nums.size();
        vector<int> result(n, 1);
        int left = 1;
        for(int i = 0; i < n; i++) {
            result[i] = left;
            left *= nums[i];
        }

        int right = 1;
        for(int i = n - 1; i >= 0; i--) {
            result[i] *= right;
            right *= nums[i];
        }
        return result;
    }
};