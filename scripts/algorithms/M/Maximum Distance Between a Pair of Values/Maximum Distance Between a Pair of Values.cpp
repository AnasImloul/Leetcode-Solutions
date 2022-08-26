// Runtime: 380 ms (Top 17.33%) | Memory: 98.4 MB (Top 73.73%)
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {

        reverse(nums2.begin(),nums2.end());
        int ans = 0;
        for(int i=0;i<nums1.size();++i){
            auto it = lower_bound(nums2.begin(),nums2.end(),nums1[i]) - nums2.begin(); //Finds first element greater than or equal to nums1[i]
            int j = nums2.size() - 1 - it; //Index of the found element in the original array
            if(i<=j) ans = max(ans,j-i); //Update distance
        }
        return ans;

    }
};