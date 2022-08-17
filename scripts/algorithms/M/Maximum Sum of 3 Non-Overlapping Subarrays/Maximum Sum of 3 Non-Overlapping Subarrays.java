class Solution {
    public int[] maxSumOfThreeSubarrays(int[] nums, int k) {
        int n = nums.length;
        int[] ans = new int[3];
        int[] pre = new int[n];
        int[] third = new int[n];
        for (int i=0;i<n;++i){ // prefix sum
            pre[i]=i==0?nums[i]:nums[i]+pre[i-1];
        }
        for (int i=n-k,max=0;i>=2*k;--i){ // find the best index for the last part
            int cur = pre[i+k-1]-pre[i-1];
            max=Math.max(max, cur);
            third[i]=cur==max?i:third[i+1];
        }
        for (int i=k,first=0,fmax=0,max=0;i+2*k-1<n;i++){
            int cur = pre[i-1]-(i==k?0:pre[i-1-k]);
            if (cur > fmax){ // compute the best index for the first part on the fly
                fmax=cur;
                first=i-k;
            }
            int a = fmax; // first
            int b = pre[i+k-1]-pre[i-1]; // middle
            int c = pre[third[i+k]+k-1]-pre[third[i+k]-1]; // last
            if (a+b+c>max){
                max=a+b+c;
                ans[0]=first;
                ans[1]=i;
                ans[2]=third[i+k];
            }
        }
        return ans;
    }
}
