class Solution:
    def minimumDeviation(self, nums: List[int]) -> int:
        
        for index, num in enumerate(nums):
            if num % 2 == 1:
                nums[index] *= 2
        
        maxHeap = []
        minVal = float("inf")
        for num in nums:
            heapq.heappush(maxHeap, -num)
            minVal = min(minVal, num)
                
        deviation = -maxHeap[0] - minVal
        while(-maxHeap[0] % 2 == 0):
            maxVal = -1 * heapq.heappop(maxHeap)
            deviation = min(deviation, maxVal - minVal)
            
            minVal = min(minVal, maxVal // 2)
            heapq.heappush(maxHeap, -(maxVal // 2))

        deviation = min(deviation, -maxHeap[0] - minVal)            
        return deviation
