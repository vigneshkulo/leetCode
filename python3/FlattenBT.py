class BinaryTree:
    def __init__(self, value, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right


def flattenBinaryTree(root):
	def dfs(curNode):
		if (curNode == None):
			return
		
		leftHead, rightHead = None, None
		leftTail, rightTail = None, None
		
		if curNode.left:
			leftHead, leftTail = dfs(curNode.left)
			if leftTail:
				leftTail.right = curNode
			curNode.left = leftTail
		else:
			leftHead = curNode
		
		if curNode.right:
			rightHead, rightTail = dfs(curNode.right)
			curNode.right = rightHead
			if rightHead:
				rightHead.left = curNode
		else:
			rightTail = curNode
		
		return (leftHead, rightTail)
		
	return dfs(root)[0]		
