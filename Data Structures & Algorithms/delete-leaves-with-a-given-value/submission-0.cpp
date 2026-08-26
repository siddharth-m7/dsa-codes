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
    bool isLeaf(TreeNode* root) {
        if(root -> left == NULL && root->right == NULL) return true;
        return false;
    }
    void dfs(TreeNode* root, int target, TreeNode* par, char side) {
        if(root == NULL) {
            return;
        }

        dfs(root->left, target, root, 'l');
        dfs(root->right, target, root, 'r');

        if(isLeaf(root) && root->val == target) {
            if(side == 'l')
                par->left = NULL; 
            else 
                par->right = NULL;
        }
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        TreeNode *par = new TreeNode(0, root, NULL);
        dfs(root, target, par, 'l');
        return par->left;
    }
};