class Solution {
public:
    int findLHS(vector<int>& nums) {
        int longest = 0;
        unordered_map<int, int> seen;
        
        for (auto val : nums) {
            seen[val] += 1;    
        }
        
        for (auto key : seen) {
            if (seen.find(key.first + 1) != seen.end()) {
                longest = max(longest, seen[key.first+1] + seen[key.first]);
            }
        }
        
        return longest;
    }
};
