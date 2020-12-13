# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        self.found = 0
        
        def searchTree(curNode):
            if (curNode == None):
                return
            
            if (curNode == p or curNode == q):
                self.found += 1
            
            searchTree(curNode.left)
            searchTree(curNode.right)
            return
        
        searchTree(root)
        if (self.found != 2):
            return None
        
        def findLCA(curNode):
            if (curNode == None):
                return
            
            if (curNode == p or curNode == q):
                return curNode
            
            left = findLCA(curNode.left)
            right = findLCA(curNode.right)
            
            if (left == p or left == q) and (right == p or right == q):
                return curNode
            
            return left or right
        
        return findLCA(root)
