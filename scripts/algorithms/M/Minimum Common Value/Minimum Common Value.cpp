// Runtime: 69 ms (Top 81.31%) | Memory: 50.80 MB (Top 73.94%)

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int i=0, j=0, element;
        while(i<nums1.size() && j<nums2.size()) {
            if(nums1[i]<nums2[j]) {
                // if the ith element in nums1 is smaller than
                // the jth element in nums2, increment pointer i
                i++;
            } else if(nums1[i]>nums2[j]) {
                // if the ith element in nums1 is greater than
                // the jth element in nums2, increment pointer j
                j++;
            } else if(nums1[i] == nums2[j]) {
                // if the ith and jth elements are equal, return it
                // this will always return the smallest element
                return nums1[i];
            }
        }
        return -1;
    }
};
