class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> output(s.length(), INT_MAX);
        
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == c) {
                output[i] = 0;
                int left = i - 1;
                while ( (left >= 0) && (output[left] > (i - left)) ) {
                    output[left] = (i - left);
                    --left;
                }
                
                int right = i + 1;
                while (right < s.length() && output[right] > (right - i)) {
                    output[right] = (right - i);
                    ++right;
                }    
            }
        }
        
        return output;
    }
};
