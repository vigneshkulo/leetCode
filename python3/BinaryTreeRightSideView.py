# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rightSideView(self, root: TreeNode) -> List[int]:
        if (root == None):
            return []
        
        queue = [root]
        
        output = []
        while (len(queue) > 0):
            curLen = len(queue)
            output.append(queue[-1].val)
            for i in range(curLen):
                item = queue.pop(0)
                if item.left:
                    queue.append(item.left)
                if item.right:
                    queue.append(item.right)
        
        return output
