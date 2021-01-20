class Solution:
    def binaryTreePaths(self, root: TreeNode) -> List[str]:
        output = []
        def dfs(curNode, curPath):
            if not curNode:
                return

            curPath.append(curNode.val)            
            if not curNode.left and not curNode.right:
                string = ""
                if len(curPath) > 0:
                    string += str(curPath[0])
                    for index in range(1, len(curPath)):
                        string += "->"
                        string += str(curPath[index])
                output.append(string)
            else:
                dfs(curNode.left, curPath)
                dfs(curNode.right, curPath)
            curPath.pop()
            
            return
        
        dfs(root, [])
        return output
