class Solution {
public:
    int nextGreaterElement(int n) {
        deque<int> num;
        bool increasing = false;
        int end = num.size() - 1;
        int start = end - 1;
        long output = 0;
        
        while (n) {
            num.push_front(n%10);
            n = n / 10;
        }
        
        while (start >= 0) {
            if (num[start] > num[start+1]) {
                if (!increasing) {
                    end = start + 1;
                    increasing = true;
                }
            } else if (num[start] < num[start+1]) {
                break;
            }
            start -= 1;
        }
        
        while (start >= 0 && num[start] >= num[end]) {
            end -= 1;
        }
        
        if (start < 0) {
            return -1;
        }
        
        num[start] ^= num[end];
        num[end] ^= num[start];
        num[start] ^= num[end];
        
        start += 1;
        end = num.size() - 1;
        while (end > start) {
            num[start] ^= num[end];
            num[end] ^= num[start];
            num[start] ^= num[end];
            start += 1;
            end -= 1;
        }
        
        return output < INT_MAX ? output : -1;
    }
};
