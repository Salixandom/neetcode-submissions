class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        int index = 0;
        while(index <= right) {
            if(nums[index] == 0) {
                swap(nums[left], nums[index]);
                left++;
                index++;
            } else if (nums[index] == 2) {
                swap(nums[right], nums[index]);
                right--;
            } else {
                index++;
            }
        }
    }
};