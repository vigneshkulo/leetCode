class Solution {
public:  
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        vector<vector<string>> output;
        
        for (auto item : strs) {
            string key = item;
            sort(key.begin(), key.end());
            map[key].push_back(item);
        }
        
        for (auto key : map) {
            output.push_back(key.second);
        }
        
        return output;
    }
};
