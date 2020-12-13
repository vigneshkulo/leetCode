# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', nodes: 'List[TreeNode]') -> 'TreeNode':
        def findLCA(curNode, p, q):
            if (curNode == None):
                return None
            
            if (curNode == p or curNode == q):
                return curNode
            
            left = findLCA(curNode.left, p, q)
            right = findLCA(curNode.right, p, q)
            
            if (left == p or left == q) and (right == p or right == q):
                return curNode
            
            return left or right
        
        while (len(nodes) > 1):
            node1 = nodes.pop()
            node2 = nodes.pop()
            nodes.append(findLCA(root, node1, node2))
            if (nodes[-1] == root):
                return root
        
        return nodes[0]
