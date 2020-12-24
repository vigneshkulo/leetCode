class Solution:
    def killProcess(self, pid: List[int], ppid: List[int], kill: int) -> List[int]:
        adjList = {}
        
        for index, child in enumerate(pid):
            parent = ppid[index]
            if parent not in adjList:
                adjList[parent] = [child]
            else:
                adjList[parent].append(child)
        
        output = []
        queue = [kill]
        
        while (len(queue)):
            curLen = len(queue)
            for i in range(curLen):
                curPid = queue.pop(0)
                output.append(curPid)
                
                if curPid in adjList:
                    for child in adjList[curPid]:
                        queue.append(child)
        
        return output
