class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int left = 0;
        int right = n-1;

        int ans = INT_MAX;

        while(left <= right){
            int mid = left + (right - left)/ 2;

            // to check if left side of the array is sorted
            if(nums[left] <= nums[mid]){
                ans = min(ans, nums[left]);
                left = mid + 1;
            }else{ 
                ans = min(ans, nums[mid]);
                right = mid - 1;
            }
        }

        return ans;
    }
};
