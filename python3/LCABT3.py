"""
# Definition for a Node.
class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None
        self.parent = None
"""

class Solution:
    def lowestCommonAncestor(self, p: 'Node', q: 'Node') -> 'Node':
        ancestors = set()
        
        while p:
            ancestors.add(p.val)
            p = p.parent
        
        while q.val not in ancestors:
            q = q.parent
        
        return q
