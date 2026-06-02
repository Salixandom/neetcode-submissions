class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0, currSum = 0;
        unordered_map<int, int> prefixSums;
        prefixSums[0] = 1;

        for(int num: nums) {
            currSum += num;
            int remove = currSum - k;
            res += prefixSums[remove];
            prefixSums[currSum]++;
        }

        return res;
    }
};