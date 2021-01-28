class Solution {
public:
    string getHex(long num) {
        if (num >= 0 && num <= 9) {
            return to_string(num);
        }
        if (num >= 10 && num <= 15) {
            return string(1, (num % 10) + 'a');
        }
        
        string quo = toHex(num / 16);
        string rem = toHex(num % 16);
        
        return quo + rem;
    }
    
    string toHex(int num) {
        string output;
        if (num < 0) {
            return getHex((long) ((long) 0x100000000) + ((long) num));
        }
        return getHex((long) num);
    }
};
