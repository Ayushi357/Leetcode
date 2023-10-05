class Solution {
public:
    int maxArea(vector<int>& height) {
        // Brute force: Try every single combination and we can make a container: O(n^2)
        // For Time: O(n): use two pointer
        
        int area = 0;

        int i = 0; 
        int j = height.size() - 1;

        while(i < j) {
            area = max(area, (j - i) * min(height[i], height[j]));
            if(height[i] <= height[j]) {
                i++;
            } else {
                j--;
            }
        }
        return area;
    }
};