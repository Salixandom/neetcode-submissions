class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq_map;
        vector<vector<int>> buckets(nums.size() + 1);
        int n = nums.size();
        for(int i: nums) freq_map[i]++;

        for(auto entry: freq_map) buckets[entry.second].push_back(entry.first);

        vector<int> res;
        for(int i = buckets.size() - 1; i >= 0; i--) {
            for(int n: buckets[i]) {
                res.push_back(n);
                if(res.size() == k) return res;
            }
        } 

        return res;
    }
};
