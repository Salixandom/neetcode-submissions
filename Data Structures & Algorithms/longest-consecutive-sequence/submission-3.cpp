class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       int res = 0;
       unordered_set<int> store(nums.begin(), nums.end());

       for(int num: nums) {
        if(store.find(num - 1) != store.end()) continue;
        
        int streak = 1;
        while(store.find(num + streak) != store.end()) {
            streak++;
        }

        res = max(res, streak);
       }

       return res; 
    }
};
