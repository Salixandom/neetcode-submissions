class Solution {
private:
    void rotateHelper(vector<int>& nums, int start, int end) {
        while(start < end) {
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        rotateHelper(nums, 0, nums.size() - 1);
        rotateHelper(nums, 0, k - 1);
        rotateHelper(nums, k, nums.size() - 1);
    }
};