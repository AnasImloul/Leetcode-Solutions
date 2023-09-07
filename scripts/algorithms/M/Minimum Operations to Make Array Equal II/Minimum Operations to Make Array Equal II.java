// Runtime: 3 ms (Top 93.2%) | Memory: 56.22 MB (Top 87.9%)

class Solution {
    public long minOperations(int[] nums1, int[] nums2, int k) {
        
    int n = nums1.length;
    long[] diff = new long[n];
    for (int i = 0; i < n; i++) {
        diff[i] = nums2[i] - nums1[i];
    }
    if(k==0){
        for(int i=0;i<n;i++)
            if(diff[i]!=0)return -1;
        return 0;
    }
    long ans = 0;
    long sum=0;
    for (int i = 0; i < n; i++) {
        sum+=diff[i];
        if (diff[i] % k != 0) {
            return -1;
        }
        ans += Math.abs(diff[i] / k);
    }

    return sum==0? ans/2:-1;
    }
}