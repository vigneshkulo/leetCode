# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class BSTIterator:

    def addNode(self, curNode):
        if curNode == None:
            return
        
        self.stack.append(curNode)
        self.addNode(curNode.left)
        return
    
    def __init__(self, root: TreeNode):
        self.stack = []
        self.addNode(root)

    def next(self) -> int:
        curNode = self.stack.pop()
        if curNode.right:
            self.addNode(curNode.right)
        
        return curNode.val

    def hasNext(self) -> bool:
        return len(self.stack) > 0
        


# Your BSTIterator object will be instantiated and called as such:
# obj = BSTIterator(root)
# param_1 = obj.next()
# param_2 = obj.hasNext()
