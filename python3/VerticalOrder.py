# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def verticalOrder(self, root: TreeNode) -> List[List[int]]:
        if (root == None):
            return []
        
        self.maxCol = -1
        self.minCol = float("inf")
        self.vertorder = {}
        
        queue = [(root, 0)]
        while (len(queue) > 0):
            curNode = queue.pop(0)
            col = curNode[1]
            curNode = curNode[0]
            
            self.maxCol = max(self.maxCol, col)
            self.minCol = min(self.minCol, col)
            
            if col in self.vertorder:
                self.vertorder[col].append(curNode.val)
            else:
                self.vertorder[col] = [curNode.val]
            
            if curNode.left:
                queue.append((curNode.left, col-1))
            if curNode.right:
                queue.append((curNode.right, col + 1))
                
        output = []
        for i in range(self.minCol, self.maxCol+1):
            output.append(self.vertorder[i])
        
        return output

