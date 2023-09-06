// Runtime: 0 ms (Top 100.0%) | Memory: 39.28 MB (Top 98.3%)

class Solution {
    int ans;
    int count[];
    public int distributeCookies(int[] cookies, int k) {
        ans= Integer.MAX_VALUE;
        count= new int[k];

        backtrack(0,cookies, k);
        return ans;
    }
    public void backtrack(int cookieNumber, int[] cookies, int k)
    {
        if(cookieNumber==cookies.length)
        {
            int max= 0;
            for(int i=0; i<k; i++)
            {
                max=Math.max(max, count[i]);

            }
            ans = Math.min(ans, max);
            return;
        }
        for(int i=0;i<k; i++)
        {
            count[i]+=cookies[cookieNumber];
            backtrack(cookieNumber+1, cookies, k);
            count[i]-=cookies[cookieNumber];
            if(count[i]==0) break;
        }
    }
}