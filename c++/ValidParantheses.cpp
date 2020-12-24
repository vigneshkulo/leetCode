class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> close;
        
        close[')'] = '(';
        close['}'] = '{';
        close[']'] = '[';
        
        stack<char> st;
        set<char> open = {'(', '{', '['};
        for (char item : s) {
            if (open.find(item) != open.end()) {
                st.push(item);
            } else {
                if (!st.size() || close[item] != st.top()) {
                    return false;
                }
                st.pop();
            }
        }
        
        if (st.size())
            return false;
        
        return true;
    }
};
