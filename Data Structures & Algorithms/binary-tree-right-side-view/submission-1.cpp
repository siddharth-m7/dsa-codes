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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<int> ans;
        while(!q.empty()) {
            int n = q.size();
            int val = -101;
            for(int i = 0; i<n; i++){
                TreeNode* node = q.front();
                q.pop();
                val = node->val;
                if(node-> left != nullptr) q.push(node->left);
                if(node-> right != nullptr) q.push(node->right);
            }
            ans.push_back(val);
        }
        return ans;
    }
};
