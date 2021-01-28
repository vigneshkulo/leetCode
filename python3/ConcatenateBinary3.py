class Solution:
    def concatenatedBinary(self, n: int) -> int:
        string = ""
        def toBinary(num):
            binVal = ""
            
            while (num):
                if (num & 1):
                    binVal += "1"
                else:
                    binVal += "0"
                num >>= 1
            return binVal
        
        binIndex = 0
        output = 0
        for i in range(n, 0, -1):
            string = toBinary(i)
            for i in range(len(string)):
                if string[i] == '1':
                    output += (2**binIndex)
                binIndex += 1
                output %= ((10 ** 9) + 7)
        return output
