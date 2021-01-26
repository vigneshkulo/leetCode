class Solution {
public:
    bool isChar(char val) {
        if (val >= 'a' && val <= 'z') {
            return true;
        }
        if (val >= 'A' && val <= 'Z') {
            return true;
        }
        if (val >= '0' && val <= '9') {
            return true;
        }
        
        return false;
    }
    
    bool isPalindrome(string s) {
        
        int start = 0;
        int end = s.length() - 1;
        
        while (end > start) {
            if (!isChar(s[start])) {
                ++start;
                continue;
            }
            if (!isChar(s[end])) {
                --end;
                continue;
            }
            
            if (tolower(s[end]) != tolower(s[start])) {
                return false;
            }
            
            ++start;
            --end;
        }
        
        return true;
    }
};
