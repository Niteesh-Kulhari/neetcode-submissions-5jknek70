class Solution {
public:
    void solve(vector<vector<int>>& ans, vector<int>& comb, vector<int>& nums, int index){
        if(index >= nums.size()){
            ans.push_back(comb);
            return;
        }

        comb.push_back(nums[index]);
        solve(ans, comb, nums, index+1);
        comb.pop_back();
        solve(ans, comb, nums, index+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> comb;
        solve(ans, comb, nums, 0);
        return ans;
    }
};
