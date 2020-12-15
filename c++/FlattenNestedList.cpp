/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
private:
    vector<int> queue;    
public:
    void addNestedIterator(vector<NestedInteger> &nestedList) {
        for (NestedInteger item : nestedList) {
            if (item.isInteger()) {
                queue.push_back(item.getInteger());
            } else {
                addNestedIterator(item.getList());
            }
        }
    }
    
    NestedIterator(vector<NestedInteger> &nestedList) {
        addNestedIterator(nestedList);
    }
    
    int next() {
        int item = queue[0];
        queue.erase(queue.begin());
        return item;
    }
    
    bool hasNext() {
        return queue.size() > 0;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
