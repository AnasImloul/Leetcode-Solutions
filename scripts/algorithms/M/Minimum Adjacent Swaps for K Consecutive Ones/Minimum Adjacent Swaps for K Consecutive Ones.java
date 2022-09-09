// Runtime: 33 ms (Top 32.47%) | Memory: 112.8 MB (Top 59.74%)
class Solution {
    public int minMoves(int[] nums, int k) {
        var gaps = new ArrayList<Integer>();
        for(int i = 0, last = -1; i < nums.length; ++i){
            if (nums[i] == 1){
                if (last > -1){
                    gaps.add(i-1-last);
                }
                last = i;
            }
        }
        int lsum = 0, rsum = 0, wlsum = 0, wrsum = 0;
        for(int i = k/2-1; i >= 0; --i){
            lsum += gaps.get(i);//lsum = 3+0
            wlsum += lsum;//wlsum = 1*3+2*0
        }
        for(int i = k/2; i < k-1; ++i){
            rsum += gaps.get(i);//rsum = 2+5
            wrsum += rsum;//wrsum = 2*2+1*5
        }
        int ans = wlsum+wrsum;
        for(int p = 0, q = k/2, r = k-1; r < gaps.size(); ++p, ++q, ++r){
            wlsum += (k/2)*gaps.get(q) - lsum;
            lsum += gaps.get(q) - gaps.get(p);

            rsum += gaps.get(r) - gaps.get(q);
            wrsum += rsum-((k-1)/2)*gaps.get(q);

            ans = Math.min(ans,wlsum+wrsum);
        }
        return ans;
    }
}