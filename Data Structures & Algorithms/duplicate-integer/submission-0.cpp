class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> num_dict;
        for(int i = 0; i < nums.size(); i++) {
            if(++num_dict[nums[i]] > 1) return true;
        }
        return false;
    }
};