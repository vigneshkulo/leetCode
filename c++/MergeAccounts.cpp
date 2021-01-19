class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, unordered_set<string>> email_map;
        unordered_map<string, string> email_name;
        vector<vector<string>> output;
        
        for (auto account : accounts) {
            for (int i = 1; i < account.size(); ++i) {
                email_map[account[1]].insert(account[i]);
                email_map[account[i]].insert(account[1]);    
                email_name[account[i]] = account[0];
            }
        }
        
        unordered_set<string> seen;
        stack<string> st;
        vector<string> final_list;
        
        for (auto item : email_map) {
            if (seen.find(item.first) != seen.end()) {
                continue;
            }
            
            st.push(item.first);
            seen.insert(item.first);
            final_list.push_back(item.first);
            while (st.size()) {
                string email = st.top();
                st.pop();
                
                for (auto nei : email_map[email]) {
                    if (seen.find(nei) == seen.end()) {
                        st.push(nei);
                        seen.insert(nei);
                        final_list.push_back(nei);                        
                    }
                }
            }
            
            sort(final_list.begin(), final_list.end());
            final_list.insert(final_list.begin(), email_name[item.first]);
            output.push_back(final_list);
            final_list.clear();
        }
        
        return output;
    }
};
