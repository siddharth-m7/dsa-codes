# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        ans = -1000000
        def dfs(root):
            
            nonlocal ans
            if not root:
                return 0
            
            left = max(0,dfs(root.left))
            right = max(0,dfs(root.right))

            curr = root.val + max(right, left, right + left)
            ans = max(ans, curr)
            # print(ans)
            return root.val + max(left, right)

        dfs(root)
        return ans