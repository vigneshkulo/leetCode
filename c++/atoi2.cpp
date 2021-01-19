class Solution {
public:
    int myAtoi(string s) {
        long output = 0;
        bool neg = false;
        bool digitRead = false;
        
        int curIndex = 0;
        
        while (curIndex < s.length()) {
            if (s[curIndex] == ' ') {
                ++curIndex;
            } else {
                break;
            }
        }
        
        if (s[curIndex] == '-') {
            neg = true;
            ++curIndex;
        } else if (s[curIndex] == '+') {
            ++curIndex;
        }
        
        while(curIndex < s.length()) {
            if (s[curIndex] >= '0' && s[curIndex] <= '9') {
                output *= 10;
                output += s[curIndex] - '0';
            } else {
                break;
            }
            ++curIndex;
            if (output > INT_MAX) {
                break;
            }         
        }
        
        if (neg) {
            output *= -1;
        }
                
        if (output > INT_MAX) {
            return INT_MAX;
        } else if (output < -INT_MAX) {
            return -INT_MAX - 1;
        } else {
            return (int) output;
        }
    }
};
