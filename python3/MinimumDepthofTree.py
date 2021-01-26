# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minDepth(self, root: TreeNode) -> int:
        if (root == None):
            return 0

        queue = [root]
        
        curLevel = 0
        while (len(queue)):
            curLen = len(queue)
            curLevel += 1            
            for i in range(curLen):
                node = queue.pop(0)
                if (node.left == None and node.right == None):
                    return curLevel
                
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
        
        return curLevel
