class Solution:
    def findNearestRightNode(self, root: TreeNode, u: TreeNode) -> TreeNode:
        if (root == None):
            return None
        
        if (u == None):
            return None
        
        queue = [root]
        found = False
        
        while (len(queue)):
            curLen = len(queue)
            for i in range(curLen):
                node = queue.pop(0)
                if found:
                    return node
                if (node == u):
                    found = True
                
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            found = False
        return None
