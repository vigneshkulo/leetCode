class Solution {
public:   
    string toHex(int num) {
        string output;
        char* hex = "0123456789abcdef";
        unsigned int val = num;
        
        if (num == 0) return "0";

        while (val) {
            output = hex[val & 0xF] + output;
            val >>= 4;
        }
        return output;
    }
};
