class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n= nums1.size();
        int m= nums2.size();
        double ans=0.0;
        vector<int> nums;
        for(int i=0; i<n; i++){
             nums.push_back(nums1[i]);
        }
        for(int i=0; i<m; i++){
             nums.push_back(nums2[i]);
        }
          sort(nums.begin() , nums.end());
        int newSize=nums.size();
        if(newSize%2==1){
            ans=nums[newSize/2];
        }
        else{
            ans=(nums[newSize/2]+nums[(newSize/2)-1])/2.0;
        }
        return ans;
    }
};