// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// You can return the answer in any order.

 

// Example 1:

// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

// Solution

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Brute Force: Take element and check it's sum with all the other numbers
        // Time: O(n^2), Space: O(n)
        
        // Making hash map: to check the complement (Target - current num) exist in hashmap
        // Mapping index of each value
        // We don't have to initialize our hash map
        // Time: O(n), Space: O(n)

        unordered_map<int, int> m;

        for(int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];
            if(m.find(diff) != m.end()) {
                return {m[diff], i};
            } 
            m[nums[i]] = i;
        }
        return {};

    }
};