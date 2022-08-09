class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
      long sum=0, minSum;
      vector<int> nums=nums1;
      int n=nums.size();
	  // Calculate the current sum of differences.
      for(int i=0;i<n;i++) sum+=abs(nums1[i]-nums2[i]);
      
      sort(nums.begin(), nums.end());
      minSum=sum;
      
      for(int i=0;i<n;i++) {
        int dist=abs(nums1[i]-nums2[i]);
        int l=0, h=n-1;
        
		// Find the number closest to nums2[i]. 
		// The closer the element, the smaller the difference.
        while(l<h) {
          int m=l+(h-l)/2;
          if(nums[m]>nums2[i]) {
            h=m;
          } else {
            l=m+1;
          }
          dist=min(dist, abs(nums2[i]-nums[m]));
        }
        dist=min(dist, abs(nums2[i]-nums[l]));
        minSum = min(minSum, sum - abs(nums1[i]-nums2[i]) + dist);
      }
      
      return minSum % 1000000007;
    }
};

