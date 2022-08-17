class Solution {
public:
    
    
    //Merging two arrays :- 
    vector<int> mergeSortedArrays(vector<int>&arr1,vector<int>&arr2){
        int n = arr1.size();
        int m = arr2.size();
        vector<int> ans(m+n);
        int i = 0;
        int j = 0;
        int mainIndex = 0;
        
        while( i < n && j < m ){
            if(arr1[i] <= arr2[j])ans[mainIndex++] = arr1[i++];
            else ans[mainIndex++] = arr2[j++];
        }
        
        while( i < n){
            ans[mainIndex++] = arr1[i++];
        }
        
        while( j < m){
            ans[mainIndex++] = arr2[j++];
        }
        return ans;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans = mergeSortedArrays(nums1,nums2);
        float median = 0;
        int n = ans.size()-1;
        
        if(n%2 != 0)
         median=(ans[n/2]+ans[(n/2)+1])/2.0; 
        else
            median=ans[n/2]; 
        return median;
        
    }
};
