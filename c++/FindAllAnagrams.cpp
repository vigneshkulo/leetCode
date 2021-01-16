class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int curStart = 0;
        int curIndex = 0;
        
        vector<int> toFind(26, 0);
        vector<int> found(26, 0);
        vector<int> output;
        
        for (auto c : p) {
            toFind[c -'a'] += 1;
        }
        
        while (curIndex < s.length()) {
            found[s[curIndex] - 'a'] += 1;
            ++curIndex;
            
            if ((curIndex-curStart) == p.length()) {
                if (toFind == found) {
                    output.push_back(curStart);
                }
                
                found[s[curStart] - 'a'] -= 1;
                curStart += 1;
            }
        }
        
        return output;
    }
};
