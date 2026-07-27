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
    bool matches(TreeNode* root, TreeNode* subRoot) {
        if(root->val != subRoot->val) return false;
        bool ans = true;
        if(root->left){
            if(subRoot->left) {
                ans = ans && matches(root->left, subRoot->left); 
            }
            else {
                ans = false;
            }
        }
        else if(subRoot->left) {
            ans = false;
        }

        if(root->right){
            if(subRoot->right) {
                ans = ans && matches(root->right, subRoot->right); 
            }
            else {
                ans = false;
            }
        }
        else if(subRoot->right) {
            ans = false;
        }
        return ans;

    }

    bool inorder(TreeNode* root, TreeNode* subRoot) {
        TreeNode* move = root;
        bool ans = false;
        if(root->left) ans = ans || inorder(root->left, subRoot);

        if(root->val == subRoot->val) {
            ans = ans || matches(root, subRoot);
        }

        if(root->right) ans = ans || inorder(root->right, subRoot);

        return ans;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return inorder(root, subRoot);
    }
};
