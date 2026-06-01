class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        if(nums.empty()) return {};

        sort(nums.begin(), nums.end());

        vector<int> res;
        int n = nums.size();
        int limit = n / 3;

        int curr = nums[0];
        int occur = 1;

        for(int i = 1; i < n; i++) {
            if(nums[i] == curr) {
                occur++;
            } else {
                if(occur > limit) {
                    res.push_back(curr);
                }

                curr = nums[i];
                occur = 1;
            }
        }

        // check the last group
        if(occur > limit) {
            res.push_back(curr);
        }

        return res;
    }
};