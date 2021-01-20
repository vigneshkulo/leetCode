class Solution:
    def rightSideView(self, root: TreeNode) -> List[int]:
        if (root == None):
            return []
        
        queue = [root]
        output = []
        
        while (len(queue)):
            curLen = len(queue)
            output.append(queue[-1].val)
            
            for i in range(curLen):
                node = queue.pop(0)
                if node.left != None:
                    queue.append(node.left)
                if node.right != None:
                    queue.append(node.right)
        
        return output
