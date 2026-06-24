class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0, r = heights.size() - 1;
        int water = 0;
        while(l <  r) {
            int subContainer = min(heights[l], heights[r]) * (r - l);
            if(subContainer > water) water = subContainer;

            if(heights[l] > heights[r]) r--;
            else l++;
        }

        return water;
    }
};
