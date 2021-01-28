class Solution:
    def concatenatedBinary(self, n: int) -> int:
        output = 0
        toShift = 0
        for i in range(1, n+1):
            if (i & (i - 1)) == 0:
                toShift += 1
            output <<= toShift
            output += i
            output %= ((10 ** 9) + 7)
        return output
