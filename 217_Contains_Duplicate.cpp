// Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

// Example 1:

// Input: nums = [1,2,3,1]
// Output: true
// Example 2:

// Input: nums = [1,2,3,4]
// Output: false
// Example 3:

// Input: nums = [1,1,1,3,3,4,3,2,4,2]
// Output: true


// Solution:

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // Brute force approach is to take a number and compare it to all the 
        // numbers in the array. Take O(n^2) time, but space: O(1)

        // sorting can also help as any duplicates will be adjacent to each othe
        // Time complexity: O(n log n), Space: O(1)

        // Extra memory using Hashset Time: O(n), Space: O(n)

        unordered_set<int> s;

        for(auto i : nums) {
            if(s.find(i) != s.end()){
                return true;
            }
            s.insert(i);
        }
        return false;
    }
};