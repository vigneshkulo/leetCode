class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int maxRooms = 0;
        vector<int> heap;
        make_heap(heap.begin(), heap.end());
        
        sort(intervals.begin(), intervals.end());
        
        for (auto interval : intervals) {            
            while (heap.size() && (-interval[0] <= heap.front())) {
                pop_heap(heap.begin(), heap.end());
                heap.pop_back();
            }
            heap.push_back(-interval[1]);
            push_heap(heap.begin(), heap.end());
            
            maxRooms = max(maxRooms, (int)heap.size());
        }
        
        return maxRooms;
    }
};
