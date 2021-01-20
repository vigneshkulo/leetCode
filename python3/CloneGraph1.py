class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        if (node == None):
            return None

        old2New = {}
        
        def createNodes(curNode):
            if (curNode == None):
                return
            
            if curNode in old2New:
                return
            
            old2New[curNode] = Node(curNode.val)
            for neigh in curNode.neighbors:
                createNodes(neigh)
        
        def addNeigh(curNode):
            if (curNode == None):
                return
            
            for neigh in curNode.neighbors:
                old2New[curNode].neighbors.append(old2New[neigh])
                
        createNodes(node)
            
        for item in old2New:
            addNeigh(item)
        
        return old2New[node]

