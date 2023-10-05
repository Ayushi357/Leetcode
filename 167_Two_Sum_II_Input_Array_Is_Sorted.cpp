class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // Brute force: O(n^2)no need to look at the remainder of the array if the combination sum > target
        // Use the fact the array is sorted, eliminating elements from the end of the array using pointers
        // shift the right pointer when sum > target, left++ if sum < target
        // Time: O(n), Space: O(1)
        int l = 0; 
        int r = numbers.size() - 1;
        vector<int> result;

        while(l < r) {
            int sum = numbers[l] + numbers[r];

            if(sum > target) {
                r--;
            }
            else if(sum < target) {
                l++;
            }
            else {
                result.push_back(l + 1);
                result.push_back(r + 1);
                break;
            }
        }
        return result;
    }
};