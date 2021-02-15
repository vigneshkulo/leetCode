class Solution:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        colors = {}
        
        for node in range(len(graph) - 1):
            if node not in colors:
                queue = [node]
                colors[node] = 0

                while (len(queue)):
                    curNode = queue.pop(0)
                    neighColor = (colors[curNode] + 1) % 2
                    for neigh in graph[curNode]:
                        if neigh in colors:
                            if colors[neigh] != neighColor:
                                return False
                        else:
                            queue.append(neigh)
                            colors[neigh] = neighColor
        return True
