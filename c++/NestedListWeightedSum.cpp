class Solution {
public:
    int sum = 0;
    
    void processList(vector<NestedInteger>& curList, int curDepth) {
        if (curList.size() == 0) {
            return;
        }
        
        for (auto item : curList) {
            if (item.isInteger()) {
                sum += (item.getInteger() * curDepth);
            } else {
                processList(item.getList(), curDepth+1);
            }
        }
        return;
    }
    
    int depthSum(vector<NestedInteger>& nestedList) {
        processList(nestedList, 1);
        return sum;
    }
};
