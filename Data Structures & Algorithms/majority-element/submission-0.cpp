class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int i: nums) {
            freq[i]++;
        }
        for(auto p: freq) {
            if(p.second > nums.size() / 2) return p.first;
        }
        return 0;
    }
};