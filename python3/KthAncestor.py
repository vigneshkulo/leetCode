class TreeAncestor:
    def __init__(self, n: int, parent: List[int]):
        self.parent = parent
        self.lopsided = False
        for i in range(len(parent)-1):
            if (parent[i] >= parent[i+1]):
                self.lopsided = True
                break
        return

    def getKthAncestor(self, node: int, k: int) -> int:
        if not(self.lopsided):
            return -1 if node - k < -1 else node - k
        
        curIndex = node
        while (k > 0) and (curIndex >= 0):
            curIndex = self.parent[curIndex]
            k -= 1
        return curIndex
