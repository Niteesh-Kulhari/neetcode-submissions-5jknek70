/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    void dfs(TreeNode* root, int& res, int maxi){
        if(root == NULL) return;
        if(root->val >= maxi){
            res++;
        }
        maxi = max(root->val, maxi);
        dfs(root->left, res, maxi);
        dfs(root->right, res, maxi);
    }

    int goodNodes(TreeNode* root) {
        int res = 0;
        if(root == NULL) return res;
        int maxi = INT_MIN;
        dfs(root, res, maxi);

        return res;
    }
};
