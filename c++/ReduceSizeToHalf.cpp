class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int curCount = 0;        
        vector<int> count;
        unordered_map<int,int> freq;
        
        for (auto item : arr) {
            freq[item] += 1;
        }
        
        for (auto item : freq){
            count.push_back(item.second);
        }
        
        sort(count.begin(), count.end());
                
        for (int i = count.size() - 1; i >= 0; --i) {
            curCount += count[i];
            
            if (curCount >= arr.size()/2) {
                return count.size() - i;
            }
        }
        return -1;
    }
};
