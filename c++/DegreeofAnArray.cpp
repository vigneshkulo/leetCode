class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, vector<int>> freqMap;
        int minWin = INT_MAX;
        int degree = 1;
        
        for (int inx = 0; inx < nums.size(); ++inx) {
            int key = nums[inx];
            
            if (freqMap.find(key) == freqMap.end()) {
                freqMap[key] = {1, inx, inx};
            } else {
                freqMap[key][0] += 1;
                freqMap[key][2] = inx;
                degree = max(degree, freqMap[key][0]);
            }
        }
        
        for (auto key : freqMap) {
            if (key.second[0] == degree) {
                minWin = min(minWin, key.second[2] - key.second[1] + 1);
            }
        }
        
        return minWin;
    }
};
