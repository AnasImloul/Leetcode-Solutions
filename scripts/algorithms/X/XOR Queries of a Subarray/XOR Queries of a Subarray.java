// Runtime: 748 ms (Top 12.05%) | Memory: 68.5 MB (Top 10.97%)
class Solution
{
    public int[] xorQueries(int[] arr, int[][] queries)
    {
        int[] ans = new int[queries.length];
        int[] xor = new int[arr.length];
        xor[0] = arr[0];
        // computing prefix XOR of arr
        for(int i = 1; i < arr.length; i++)
        {
            xor[i] = arr[i] ^ xor[i-1];
        }
        for(int i = 0; i < queries.length; i++)
        {
            // if query starts from something other than 0 (say i), then we XOR all values from arr[0] to arr[i-1]
            if(queries[i][0] != 0)
            {
                ans[i] = xor[queries[i][1]];
                for(int j = 0; j < queries[i][0]; j++)
                {
                    ans[i] = arr[j] ^ ans[i];
                }
            }
            // if start of query is 0, then we striaght up use the prefix XOR till ith element
            else
                ans[i] = xor[queries[i][1]];
        }
        return ans;
    }
}