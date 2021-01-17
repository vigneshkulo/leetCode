class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> heap;        
        make_heap(heap.begin(), heap.end());
        
        for (auto num : nums) {
            num *= -1;
            if (heap.size() < k) {
                heap.push_back(num);
                push_heap(heap.begin(), heap.end());
            } else if (num < heap.front()) {
                pop_heap(heap.begin(), heap.end());
                heap.pop_back();

                heap.push_back(num);
                push_heap(heap.begin(), heap.end());
            }
        } 
        return -heap.front();
    }
};
