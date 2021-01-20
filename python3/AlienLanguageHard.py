class Node:
    def __init__(self):
        self.char = ''
        self.incoming = 0
        self.next = []

class Solution:
    def alienOrder(self, words: List[str]) -> str:
        count = 0
        unique = {}
        output = ""
        processNodes = []
        visited = set()
        
        for word in words:
            for char in word:
                if char not in unique:
                    node = Node()
                    node.char = char
                    unique[char] = node
                    count += 1
                
        for i in range(1, len(words)):
            prev = words[i-1]
            cur = words[i]
            
            index1 = 0
            index2 = 0
            
            while (index1 < len(prev) and index2 < len(cur) and prev[index1] == cur[index2]):
                index1 += 1
                index2 += 1
            
            if (index1 == len(prev)):
                continue
            
            if (index2 == len(cur)):
                return ""

            unique[prev[index1]].next.append(unique[cur[index2]])
            unique[cur[index2]].incoming += 1

        for item in unique:
            if (unique[item].incoming == 0):
                processNodes.append(item)
        
        while (len(processNodes)):
            item = processNodes.pop(0)
            if item in visited:
                return ""
            
            visited.add(item)
            if (unique[item].incoming == 0):
                output += item
                for nei in unique[item].next:
                    nei.incoming -= 1
                    if nei.incoming == 0:
                        processNodes.append(nei.char)
        
        if len(output) != count:
            return ""

        return output
