// Runtime: 194 ms (Top 26.64%) | Memory: 76.2 MB (Top 86.68%)
class Solution {
    public int countRangeSum(int[] nums, int lower, int upper) {
        int n = nums.length, ans = 0;
        long[] pre = new long[n+1];
        for (int i = 0; i < n; i++){
            pre[i+1] = nums[i] + pre[i];
        }
        Arrays.sort(pre);
        int[] bit = new int[pre.length+2];
        long sum = 0;
        for (int i = 0; i < n; i++){
            update(bit, bs(sum, pre), 1);
            sum += nums[i];
            ans += sum(bit, bs(sum-lower, pre)) - sum(bit, bs(sum-upper-1, pre));
        }
        return ans;
    }

    private int bs(long sum, long[] pre){ // return the index of first number bigger than sum
        int lo = 0, hi = pre.length;
        while(lo < hi){
            int mid = (lo+hi) >> 1;
            if (pre[mid]>sum){
                hi=mid;
            }else{
                lo=mid+1;
            }
        }
        return lo;
    }

    private void update(int[] bit, int idx, int inc){
        for (++idx; idx < bit.length; idx += idx & -idx){
            bit[idx] += inc;
        }
    }

    private int sum(int[] bit, int idx){
        int ans = 0;
        for (++idx; idx > 0; idx -= idx & -idx){
            ans += bit[idx];
        }
        return ans;
    }
}