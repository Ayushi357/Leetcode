class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Brute force: 3 loops // we want to eliminate the duplicates
        // The solution is to sort the input array, if we find duplicate then we can skip it as the left 
        // neighbor is the same value
        // problem reduces to two sum II
        // sum > 0, r-- (shift right pointer)
        // sum < 0, l++ (shift left pointer)

        // Time: O(n log n) + O(n^2) (1 loop to get first value, and 2nd loop to solve two sum)
        // space: O(n)

        vector<vector<int>> result;

        // if(nums.size() < 3) {
        //     return result;
        // }
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 2; i++) {
            if(nums[i] > 0) {
                break;
            }
            if(i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int j = i + 1;
            int k = nums.size() - 1;

            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum > 0) {
                    k--;
                }
                else if(sum < 0) {
                    j++;
                }
                else {
                    result.push_back({nums[i], nums[j], nums[k]});
                    while(j < k && nums[j] == nums[j + 1]) { j++; }
                    j++;
                    while(j < k && nums[k] == nums[k - 1]) { k--; }
                    k--;
                }
            }
            
        }
        return result;
    }
};