class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int map[26] = {0};
        
        for (char c : magazine) {
            map[c-'a'] += 1;
        }
        
        for (char c : ransomNote) {
            if (map[c - 'a'] <= 0) {
                return false;
            }
            map[c - 'a'] -= 1;
        }
        
        return true;
    }
};
