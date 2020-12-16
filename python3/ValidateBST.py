class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        self.isValid = True
        def dfs(curNode, minVal, maxVal):
            if (curNode == None):
                return True
            
            if (curNode.val >= maxVal) or (curNode.val <= minVal):
                return False

            return dfs(curNode.left, minVal, curNode.val) and dfs(curNode.right, curNode.val, maxVal)
        
        return dfs(root, float("-inf"), float("inf"))
