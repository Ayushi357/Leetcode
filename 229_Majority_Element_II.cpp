class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // Time: O(n), Space: O(n)
        vector<int> result;
        unordered_map<int, int> m;

        for(int i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
        }
        for(auto it = m.begin(); it != m.end(); it++) {
            if(it->second > floor(nums.size()/3)) {
                result.push_back(it->first);
            }
        }
        return result;
    }
};