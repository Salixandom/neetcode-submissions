// selection sort // O(n^2)

class Solution {
private:
    void merge(int low, int mid, int high, vector<int>& nums) {
        int left = low, right = mid + 1;
        vector<int> temp;
        while(left <= mid && right <= high) {
            if(nums[left] <= nums[right]) {
                temp.push_back(nums[left]);
                left++;
            } else {
                temp.push_back(nums[right]);
                right++;
            }
        }
        while(left <= mid) {
            temp.push_back(nums[left]);
            left++;
        }
        while(right <= high) {
            temp.push_back(nums[right]);
            right++;
        }

        for(int i = low; i <= high; i++) nums[i] = temp[i - low];
    }

    void merge_sort(int low, int high, vector<int>& nums) {
        if(low >= high) return;
        int mid = (high + low) / 2;
        merge_sort(low, mid, nums);
        merge_sort(mid + 1, high, nums);
        merge(low, mid, high, nums);
        return;
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        merge_sort(0, nums.size() - 1, nums);
        return nums;
    }
};