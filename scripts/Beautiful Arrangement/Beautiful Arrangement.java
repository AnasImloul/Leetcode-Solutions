class Solution {
    int N;
    Integer[][] memo;
    public int countArrangement(int n) {
        this.N = n;
        memo = new Integer[n+1][1<<N];
        return permute(1, 0);
    }
    
    private int permute(int index, int mask)
    {
        if (mask == (1<<N)-1)
            return 1;
        if (memo[index][mask] != null)
            return memo[index][mask];
        int res = 0;
        for (int i = 1; i <= N; i++)
        {
            if ((mask & (1<<(i-1))) == 0 && (index % i == 0 || i % index == 0))
            {
                mask |= (1<<(i-1));
                res += permute(index+1, mask);
                mask ^= (1<<(i-1));
            }
        }
        return memo[index][mask]=res;
    }
}
