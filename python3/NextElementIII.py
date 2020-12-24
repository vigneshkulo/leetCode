class Solution:
    def nextGreaterElement(self, n: int) -> int:
        num = str(n)
        if (len(num) <= 1):
            return -1
        
        num = list(num)
        end = len(num) -1
        start = end - 1
        
        increasing = False
        while (start >= 0):
            if (num[start] > num[start+1]):
                if not(increasing):
                    end = start + 1
                    increasing = True
            elif (num[start] < num[start+1]):
                break
            
            start -= 1
        
        while (start >= 0) and (num[start] >= num[end]):
            end -= 1
        
        if start < 0:
            return -1
        
        num[start], num[end] = num[end], num[start]
        start += 1
        end = len(num) - 1
        while (end > start):
            num[start], num[end] = num[end], num[start]
            start += 1
            end -= 1
            
        output = int("".join(item for item in num))
        return output if output < (2**31) else -1
