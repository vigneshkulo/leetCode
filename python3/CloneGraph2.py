class Solution:
    def __init__(self):
        self.old2New = {}
        
    def cloneGraph(self, node: 'Node') -> 'Node':
        if (node == None):
            return None
        
        if node in self.old2New:
            return self.old2New[node]
        
        self.old2New[node] = Node(node.val)
        
        for neigh in node.neighbors:
            self.old2New[node].neighbors.append(self.cloneGraph(neigh))
        
        return self.old2New[node]
