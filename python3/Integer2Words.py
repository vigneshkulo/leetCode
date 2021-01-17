class Solution:
    def numberToWords(self, num: int) -> str:
        if (num == 0):
            return "Zero"
        
        output = ""
        index = 0
        
        digits = ["", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"]
        tenths = ["", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"]
        spec = ["", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"]
        metrics = ["", "Thousand", "Million", "Billion"]
        
        def get3digitWord(val):
            if val == 0:
                return ""
            
            curWord = ""
            hundreds = val // 100
            if (hundreds):
                curWord += digits[hundreds]
                curWord += " Hundred"
            
            special = val % 100
            if (11 <= special <= 19):
                if curWord != "":
                    curWord += " "
                curWord += spec[special-10]
            else:
                tens = (val % 100) // 10
                if (tens):
                    if curWord != "":
                        curWord += " "
                    curWord += tenths[tens]

                ones = (val % 10)
                if (ones):
                    if curWord != "":
                        curWord += " "
                    curWord += digits[ones]
            
            return curWord
        
        while (num):
            cur = get3digitWord(num%1000)
            if cur != "":
                output = cur + " " + metrics[index] + " " + output

            index += 1
            num //= 1000
        
        output = output.lstrip()
        output = output.rstrip()
        return output
