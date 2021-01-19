class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> seen(256, -1);
        
        int maxWindow = 0;
        int start = 0;
        int end = 0;
        int index = -1;
        
        while (end < s.length()) {
            index = s[end] - ' ';
            if (seen[index] == -1) {
                seen[index] = end;
            } else {
                while (start < end && start <= seen[index]) {
                    seen[s[start] - ' '] = 0;
                    ++start;
                }
                seen[index] = end;
            }
            
            maxWindow = max(maxWindow, end - start + 1);
            ++end;
        }
        
        return maxWindow;
    }
};
