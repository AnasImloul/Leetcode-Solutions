class Solution {    
    private int trUtil(int n, int m, int[][] cache)
    {
        if (n > m)
        {
            int temp = n;
            n = m;
            m = temp;
        }
        
        if (cache[n][m] != 0)
            return cache[n][m];
        
        if (n == 0)
        {
            cache[0][m] = 0;
            return 0;
        }
        
        if (n == 1)
        {
            cache[n][m] = m;
            return m;
        }
        
        if (n == m)
        {
            cache[n][m] = 1;
            return 1;
        }
        
        if (m % n == 0)
        {
            cache[n][m] = m/n;
            return m/n;
        }
        
        if (m > 2 * n)
        {
            int num = (m / n) - 1;
            int newM = m - num*n;            
            cache[n][m] = num + trUtil(n, newM, cache);
            return cache[n][m];
        }
        
        cache[n][m] = 1 + trUtil(Math.min(n, m-n), Math.max(n, m-n), cache);
        
        // if 1 < n < m < 2n then we do the following
        // Let i be size of big square
        // Let j be size of horizontal extension beyond big square
        // Horizontal side is of len m, Vertical side is of len n
        // Bigger square is in bottom left corner, smaller sqaure attached to bigger
        // is in bottom right corner
        //
        /*  ---------------------------
            |                      *  |
            |                      *  |
            |--------i--------..j.>*  |
            |                |        |
            n                |        |
            |                |--------|
            |                |        |
            |                |        |
            --------------m------------
        */
        
        for (int i = (m+1)/2; i < n; i++)
        {
            for (int j = 0; j <= (m - i); j++)
            {
                cache[n][m] = Math.min(cache[n][m], 2 +
                                      trUtil(n-i, i+j, cache) +
                                      trUtil(n - (m-i), (m-i) - j, cache) +
                                      trUtil(j, i - (m-i), cache));
            }
        }
        
        return cache[n][m];
    }
    
    
    public int tilingRectangle(int n, int m) {
        int temp = Math.min(n, m);
        m = Math.max(n, m);
        n = temp;
        
        int[][] cache = new int[n+1][m+1];
        return trUtil(n, m, cache);
    }
}