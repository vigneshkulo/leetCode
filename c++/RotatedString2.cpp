class Solution {
public:
    bool rotateString(string A, string B) {
        int curIndex = 0;
        
        if (A.length() != B.length()) {
            return false;
        }
        if (A.length() == 0 && B.length() == 0) {
            return true;
        }
        
        string temp = B + B;
        int srcIndex = 0, dstIndex = 0;
                
        while (curIndex < temp.length()) {
            srcIndex = 0;
            dstIndex = curIndex;
            while (srcIndex < A.length() && A[srcIndex] == temp[dstIndex]) {
                ++srcIndex;
                ++dstIndex;
            }
            if (srcIndex == A.length()) {
                return true;
            }
            
            ++curIndex;
        }
        return false;
    }
};
