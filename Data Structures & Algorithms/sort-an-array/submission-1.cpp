// selection sort // O(n^2)

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n - 1; i++) {
            int min = i;
            for(int j = i; j < n; j++) {
                if(nums[j] < nums[min]) min = j;
            }
            int temp = nums[min];
            nums[min] = nums[i];
            nums[i] = temp;
        }
        return nums;
    }
};