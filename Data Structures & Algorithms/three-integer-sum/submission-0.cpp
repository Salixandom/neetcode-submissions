class Solution {
private:
    vector<vector<int>> twoSum(vector<int>& numbers, int start, int target) {
        vector<vector<int>> res;
        int i = start;
        int j = numbers.size() - 1;

        while(i < j) {
            int sum = numbers[i] + numbers[j];
            if(sum > target) j--;
            else if(sum < target) i++;
            else {
                res.push_back({numbers[i], numbers[j], -target});
                while(i < j && numbers[i] == numbers[i+1]) i++;
                while(i < j && numbers[j] == numbers[j-1]) j--;
                i++;
                j--;
            }
        }

        return res;
    }
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            
            vector<vector<int>> triplets = twoSum(nums, i + 1, -nums[i]);
            res.insert(res.end(), triplets.begin(), triplets.end());
        }

        return res;
    }
};