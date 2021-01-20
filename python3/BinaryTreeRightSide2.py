class Solution:
    def rightSideView(self, root: TreeNode) -> List[int]:
        output = []
        def helper(curNode, curLevel):
            if not curNode:
                return
            
            if (len(output) == curLevel):
                output.append(curNode.val)
            
            helper(curNode.right, curLevel + 1)
            helper(curNode.left, curLevel + 1)
        
        helper(root, 0)
        return output

