# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def boundaryOfBinaryTree(self, root: TreeNode) -> List[int]:
        if root == None:
            return []
        
        if root.left == None and root.right == None:
            return [root.val]
        
        left = []
        right = []
        def dfs(curNode, direc):
            if (curNode == None):
                return
            
            if curNode.left == None and curNode.right == None:
                return
            
            if direc == 0:
                left.append(curNode.val)
                node1, node2 = curNode.left, curNode.right
            else:
                right.append(curNode.val)
                node1, node2 = curNode.right, curNode.left
                
            if (node1 != None):
                dfs(node1, direc)
            else:
                dfs(node2, direc)
            
            return
        
        dfs(root.left, 0)
        dfs(root.right, 1)
        
        leaves = []
        def addLeaves(curNode):
            if curNode == None:
                return
            
            if curNode.left == None and curNode.right == None:
                leaves.append(curNode.val)
                return
            
            addLeaves(curNode.left)
            addLeaves(curNode.right)
            return
        
        addLeaves(root)
                
        output = []
        output.append(root.val)
        
        for item in left:
            output.append(item)
        
        for item in leaves:
            output.append(item)
        
        for i in range(len(right)-1, -1, -1):
            output.append(right[i])
        return output
