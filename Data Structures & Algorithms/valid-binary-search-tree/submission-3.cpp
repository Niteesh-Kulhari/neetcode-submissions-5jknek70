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
    bool check(TreeNode* root, int left, int right){
        if(root == NULL) return true;

        if(root->val <= left || root->val >= right){
            return false;
        }

        return check(root->left, left, root->val) && check(root->right, root->val, right);

        //return true;
    }

    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;

        return check(root, INT_MIN, INT_MAX);
    }
};
