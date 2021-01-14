/* Time: O(n), Space: O(1) */

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0) {
            return;
        }
        
        int start = 0;
        int end = m-1;
        
        /* Reverse first m elements */
        while (end > start) {
            nums1[start] ^= nums1[end];
            nums1[end] ^= nums1[start];
            nums1[start] ^= nums1[end];
            ++start;
            --end;
        }
        
        start = 0;
        end = nums1.size()-1;
        
        /* Reverse entire nums1 array */
        while (end > start) {
            nums1[start] ^= nums1[end];
            nums1[end] ^= nums1[start];
            nums1[start] ^= nums1[end];
            ++start;
            --end;
        }
        
        int index1 = nums2.size();
        int index2 = 0;
        int outputIndex = 0;

        /* The first n elements in nums1 are zeros, do merge */
        while (index1 < nums1.size() && index2 < nums2.size()) {
            if (nums1[index1] < nums2[index2]) {
                nums1[outputIndex] = nums1[index1];
                ++index1;
            } else {
                nums1[outputIndex] = nums2[index2];
                ++index2;
            }
            ++outputIndex;
        }
        
        while (index1 < nums1.size()) {
            nums1[outputIndex] = nums1[index1];
            ++index1;
            ++outputIndex;                            
        }
        
        while (index2 < nums2.size()) {
            nums1[outputIndex] = nums2[index2];
            ++index2;
            ++outputIndex;            
        }
    }
};
