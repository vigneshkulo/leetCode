class Solution:

    def __init__(self, nums: List[int]):
        self.sortedNums = nums
        return
        
    def pick(self, target: int) -> int:        
        occurences = []
        
        for index, num in enumerate(self.sortedNums):
            if num == target:
                occurences.append(index)
                
        randIndex = random.randint(0, len(occurences)-1)
        
        return occurences[randIndex]
