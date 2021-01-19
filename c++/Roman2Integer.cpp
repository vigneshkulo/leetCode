class Solution {
public:
    int romanToInt(string s) {
        
        int curIndex = 0;
        char prev = s[0];
        int output = 0;
        int diff = 0;
        
        vector<int> romanValues = {1, 5, 10, 50, 100, 500, 1000};
        unordered_map<char, int> romanIndex;
        romanIndex['I'] = 0;
        romanIndex['V'] = 1;
        romanIndex['X'] = 2;
        romanIndex['L'] = 3;
        romanIndex['C'] = 4;
        romanIndex['D'] = 5;
        romanIndex['M'] = 6;
        
        while (curIndex < s.length()) {
            diff = romanIndex[s[curIndex]] - romanIndex[prev];
            if (diff == 1 || diff == 2) {
                output -= (2 * romanValues[romanIndex[prev]]);
            }
            output += romanValues[romanIndex[s[curIndex]]];
            
            prev = s[curIndex];
            ++curIndex;
        }
        
        return output;
    }
};
