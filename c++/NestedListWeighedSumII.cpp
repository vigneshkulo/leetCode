/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    
    int getDepth(vector<NestedInteger>& nestedList) {
        if (nestedList.size() == 0) {
            return 0;
        }
        
        int maxDepth = 1;
        for (auto& item : nestedList) {
            if (!item.isInteger()) {
                maxDepth = max(maxDepth, getDepth(item.getList()) + 1);
            }
        }
        
        return maxDepth;
    }
    
    int processList(vector<NestedInteger>& nestedList, int curDepth) {
        if (nestedList.size() == 0) {
            return 0;
        }
        
        int value = 0;
        for (auto& item : nestedList) {
            if (!item.isInteger()) {
                value += processList(item.getList(), curDepth - 1);
            } else {
                value += (item.getInteger() * curDepth);
            }
        }
        
        return value;
    }
    
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int depth = getDepth(nestedList);
        
        return processList(nestedList, depth);
    }
};
