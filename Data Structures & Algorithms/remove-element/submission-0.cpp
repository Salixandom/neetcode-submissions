class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> res;
        for(int i: nums) {
            if (i != val) res.push_back(i);
        }
        nums = res;

        return nums.size();
    }
};