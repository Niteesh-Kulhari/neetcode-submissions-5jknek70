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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> map;

        for(int i=0; i<inorder.size(); i++){
            map[inorder[i]] = i;
        }

        TreeNode* root = buildTree(preorder, 0, preorder.size()-1,
                                    inorder, 0, inorder.size()-1, map);

        return root;
    }

    TreeNode* buildTree(vector<int>& preOrder, int preStart, int preEnd,
                        vector<int>& inOrder, int inStart, int inEnd,
                        unordered_map<int, int>& map){

        if(preStart > preEnd || inStart > inEnd){
            return NULL;
        }

        TreeNode* temp = new TreeNode(preOrder[preStart]);
        int inroot = map[temp->val];
        int numsLeft = inroot - inStart;

        temp->left = buildTree(preOrder, preStart+1, preStart + numsLeft,
                                inOrder, inStart, inroot-1,
                                map);

        temp->right = buildTree(preOrder, preStart + numsLeft + 1, preEnd,
                                inOrder, inroot + 1, inEnd, map);

        return temp;

    }
};
