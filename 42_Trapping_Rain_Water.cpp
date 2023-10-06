class Solution {
public:
    int trap(vector<int>& height) {
        // take max height on left and max height on right and take minimum of both (bottleneck)
        // min(max(left height), max(right height)) - height[i]
        // Solution 1: Time: O(n), Memory: O(n)
        // we need to keep maxLeft array and maxRight array
        // min(L, R) - height[i] >= 0
        // Solution 2: Time: O(n), Memory: O(1)
        // With two pointers, left = 0, right = height.size() - 1
        // maxL = 0, maxR = 1 (Shift the smaller one)
        // but we don't need the maxR as we just need the min of maxL, and maxR

        int l = 0;
        int r = height.size() - 1;
        int leftMax = height[l];
        int rightMax = height[r];
        int total = 0;

        if(height.empty()) {
            return 0;
        }
        while(l < r) {
            if(leftMax <= rightMax) {
                l++;
                leftMax = max(leftMax, height[l]);
                total += leftMax - height[l];
            } else {
                r--;
                rightMax = max(rightMax, height[r]);
                total += rightMax - height[r];
            }
        }
        return total;
    }
};