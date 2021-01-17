class Solution {
public:
    int count = 0;
    int limit = 0;
    
    void dfs(int curLen, int curIndex) {
        if (curLen >= limit) {
            ++count;
            return;
        }
        
        for (int i = curIndex; i < 5; ++i) {
            dfs(curLen+1, i);
        }
        return;
    }
    
    int countVowelStrings(int n) {
        limit = n;
        dfs(0, 0);
        return count;
    }
};
