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
        
        output = [root.val]
        if root.left == None and root.right == None:
            return output 
        
        left = []
        right = []
        leaves = []
        
        ROOT = 0
        LEFT = 1
        RIGHT = 2
        INNER = 3
        
        def dfs(curNode, flag):
            if (curNode == None):
                return
            
            if curNode.left == None and curNode.right == None:
                leaves.append(curNode.val)
                return
            
            if flag == LEFT:
                left.append(curNode.val)
            elif flag == RIGHT:
                right.append(curNode.val)

            newFlag = -1
            if flag == ROOT or flag == LEFT:
                newFlag = LEFT
            elif flag == RIGHT:
                if curNode.right == None:
                    newFlag = RIGHT
                else:
                    newFlag = INNER
            dfs(curNode.left, newFlag)
            
            if flag == ROOT or flag == RIGHT:
                newFlag = RIGHT
            elif flag == LEFT:
                if curNode.left == None:
                    newFlag = LEFT
                else:
                    newFlag = INNER
            dfs(curNode.right, newFlag)
            
            return
        
        dfs(root, ROOT)
        
        for item in left:
            output.append(item)
        
        for item in leaves:
            output.append(item)
        
        for i in range(len(right)-1, -1, -1):
            output.append(right[i])
                   
        return output
