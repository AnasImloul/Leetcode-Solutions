// Runtime: 111 ms (Top 42.96%) | Memory: 60.80 MB (Top 81.1%)

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int temp = 0;
        for(auto i : nums2)
        {
            temp = temp ^ i;
                
        }
        int a = 0;
        for(int i = 0; i < nums1.size(); i++)
        {
            if(nums2.size() % 2)
                nums1[i] = temp ^ nums1[i];
            else
                nums1[i] = temp;
        }
        for(auto i : nums1)
            a = a^i;
        
        return a;
    }
};
