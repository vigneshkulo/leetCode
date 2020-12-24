class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        unordered_map<int, vector<int>> adjList;
        vector<int> output;
        
        for (int index = 0; index < pid.size(); ++index) {
            int parent = ppid[index];
            adjList[parent].push_back(pid[index]);
        }
        
        queue<int> q;
        q.push(kill);
        
        while (q.size()) {
            int curLen = q.size();
            for (int i = 0; i < curLen; ++i) {
                int curPid = q.front();
                output.push_back(curPid);
                q.pop();
                
                for (auto child : adjList[curPid]) {
                    q.push(child);
                }
            }
        }
        
        return output;
    }
};
