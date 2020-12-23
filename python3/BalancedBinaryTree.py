class Solution:
    def isBalanced(self, root: TreeNode) -> bool:
        
        def dfs(curNode):
            if curNode == None:
                return (True, 0)
            
            left, ldep = dfs(curNode.left)
            if ldep < 0:
                return (False, -1)
            
            right, rdep = dfs(curNode.right)
            if rdep < 0:
                return (False, -1)
            
            if abs(ldep - rdep) > 1:
                return (False, -1)
                        
            return (True, max(ldep, rdep) + 1)
        
        return dfs(root)[0]
