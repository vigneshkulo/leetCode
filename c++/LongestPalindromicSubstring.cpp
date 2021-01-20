class Solution {
private:
        int maxStart = 0;
        int maxEnd = 0;
    
public:
    void checkIndex(int evenOrOdd, string s) {
        int start = 0, end = 0;
        
        for (int i = 0; i < s.length(); ++i) {
            start = i - 1;
            end = i + evenOrOdd;
            
            while (start >= 0 && end < s.length()) {
                if (s[start] == s[end]) {
                    --start;
                    ++end;
                } else {
                    break;
                }
            }
            
            ++start;
            --end;
            
            if ((end - start) > (maxEnd - maxStart)) {
                maxStart = start;
                maxEnd = end;
            }
        }
    }
    
    string longestPalindrome(string s) {    
        checkIndex(1, s);
        checkIndex(0, s);
        return s.substr(maxStart, maxEnd-maxStart+1);
    }
};
