class Solution {
public:
    void sum(vector<vector<int>>& ans, vector<int>& comb, vector<int>& nums, int index, int target){
        if(target < 0){
            return;
        }
        
        if(target == 0){
            ans.push_back(comb);
            return;
        }

        if(index >= nums.size()){
            return;
        }

        comb.push_back(nums[index]);
        sum(ans, comb, nums, index, target - nums[index]);
        comb.pop_back();
        sum(ans, comb, nums, index+1, target);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> comb;
        sum(ans, comb, nums, 0, target);
        return ans;
    }
};
