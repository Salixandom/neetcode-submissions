class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int len = 1;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++) {
            int localLen = 1;
            int start = nums[i];
            for(int j = i + 1; j < nums.size(); j++) {
                if(nums[j] == start + 1) {
                    localLen++;
                    start =  nums[j];
                }
            }

            if(localLen > len) len =  localLen;
        }
        
        return len;
    }
};
