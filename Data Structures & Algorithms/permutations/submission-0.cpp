class Solution {
public:
    void solve(vector<vector<int>>& ans, vector<int>& comb, vector<int>& nums, vector<bool>& flags, int index){
        if(comb.size() == nums.size()){
            ans.push_back(comb);
            return;
        }

        for(int i=0; i<nums.size(); i++){
            if(flags[i]) continue;

            flags[i] = true;
            comb.push_back(nums[i]);

            solve(ans, comb, nums, flags, i+1);

            comb.pop_back();
            flags[i] = false;

        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> comb;
        vector<vector<int>> ans;
        vector<bool> flags(nums.size(), false);

        solve(ans, comb, nums, flags, 0);

        return ans;
    }
};
