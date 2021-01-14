class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {       
        sort(people.begin(), people.end());
        
        int output = 0;
        int start = 0;
        int end = people.size() - 1;
        
        while (end >= start) {
            if (people[start] + people[end] <= limit) {
                ++start;
            }
            --end;
            ++output;
        }
        
        return output;
    }
};
