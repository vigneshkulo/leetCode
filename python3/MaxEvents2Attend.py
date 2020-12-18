class Solution:
    def maxEvents(self, events: List[List[int]]) -> int:
        events.sort(key = lambda x: x[0])
        sortedend  = []
        
        eventInx = 0
        numWays = 0
        
        start = events[0][0]
        end = max(event[1] for event in events)
        
        for curDay in range(start, end+1):
            while (eventInx < len(events)) and (events[eventInx][0] == curDay):
                heapq.heappush(sortedend, events[eventInx][1])
                eventInx += 1
                                    
            if (len(sortedend) > 0):
                item = heapq.heappop(sortedend)
                if (item >= curDay):
                    numWays += 1
            
            while (len(sortedend) > 0) and (sortedend[0] <= curDay):
                heapq.heappop(sortedend)
            
        return numWays
