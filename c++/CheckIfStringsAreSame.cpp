class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int windex1 = 0;
        int cindex1 = 0;
        int windex2 = 0;
        int cindex2 = 0;
        
        while (windex1 < word1.size() && windex2 < word2.size()) {
            while (cindex1 < word1[windex1].size() && cindex2 < word2[windex2].size()) {
                if (word1[windex1][cindex1] != word2[windex2][cindex2]) {
                    return false;
                }
                ++cindex1;
                ++cindex2;
            }
            
            if (cindex1 == word1[windex1].size()) {
                cindex1 = 0;
                ++windex1;
            }
            if (cindex2 == word2[windex2].size()) {
                cindex2 = 0;
                ++windex2;
            }            
        }
        
        return (windex1 == word1.size() && windex2 == word2.size());
    }
};
