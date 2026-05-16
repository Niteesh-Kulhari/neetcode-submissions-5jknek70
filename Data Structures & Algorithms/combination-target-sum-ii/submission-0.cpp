class Solution {
public:
    void solve(vector<vector<int>>& ans, vector<int>& sub, vector<int>& candidates, int target, int index){
        // if(index >= candidates.size() || target < 0){
        //     return;
        // }

        if(target == 0){
            ans.push_back(sub);
            return;
        }

        for(int i=index; i<candidates.size(); i++){
            if(i > index && candidates[i] == candidates[i-1]){
                continue;
            }

            if(candidates[i] > target) break;

            sub.push_back(candidates[i]);
            solve(ans, sub, candidates, target - candidates[i], i+1);
            sub.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> sub;
        sort(candidates.begin(), candidates.end());
        solve(ans, sub, candidates, target, 0);
        return ans;
    }
};
