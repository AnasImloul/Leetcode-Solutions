// Runtime: 624 ms (Top 51.93%) | Memory: 473.4 MB (Top 35.91%)
/**
Cases:

diff > 0 meaning we need to pick more chars in s1
diff < 0 meaning we need to pick more chars in s2

-1000 < diff < 1000 as there can be at most 3 digits in the string meaning largest digits are 999

1. s1[i] == s2[j] and diff = 0
    increment i+1 and j+1

2. if s1[i] is not digit and diff > 0 then increment i i+1, diff
3. if s2[j] is not digit and diff < 0 then increment j j+1, diff
4. if s1[i] is digit then get digit value and decrement diff val as we have covered such chars in the s1 string
    and increment i i+1, diff-val
5. if s2[j] is digit then get digit value and increment diff val as we need to cover such chars in the s2 string and
    increment j, j+1, diff+val

     01234
s1 = l123e
s2 = 44

i: 0
j: 0
diff: 0
    // Wildcard matching on s2[j]
    val = 4, diff = 0+4 j = 1

    i: 0
    j: 1
    diff: 4
    // Literal matching on s1[i]
    increment ith pointer as ith is a literal and we can move on to next char in s1 and decrement diff

        i: 1
        j: 1
        diff: 3
        // Wildcard matching on s1[i]
        val = 1 diff = 3-1 = 2 increment i

            i: 2
            j: 1
            diff: 2
            // Wildcard matching on s1[i]
            val = 2 diff = 2-2 = 0 increment i

                i: 3
                j: 1
                diff: 0
                // Wildcard matching on s1[i]
                val=3 diff = 0-3 = -3, increment i

                    i: 4
                    j: 1
                    diff: -3
                    // Wildcard matching on s2[j]
                    val = 4 diff = -3+4 =1 increment j

                        i: 4
                        j: 2
                        diff: 1
                         // Literal matching on s1[i]
                         decrement i-1 and increment i

                            i=5
                            j=2
                                diff==0 return true
                        dp[4][2][1] = true
                        return true
                    return dp[4][1][1000-3] = true
                return dp[3][1][0] = true

            i: 2
            j: 1
            diff: 2
            return dp[2][1][2] = true
            return true

        i: 0
        j: 1
        diff: 4
        return dp[0][1][4] = true
    return true
*/

class Solution {
    //112ms
     public boolean possiblyEquals(String s1, String s2) {
         return helper(s1.toCharArray(), s2.toCharArray(), 0, 0, 0, new Boolean[s1.length()+1][s2.length()+1][2001]);
     }

     boolean helper(char[] s1, char[] s2, int i, int j, int diff, Boolean[][][] dp) {
         if(i == s1.length && j == s2.length) {
             return diff == 0;
         }

         if(dp[i][j][diff+1000] != null)
             return dp[i][j][diff+1000];

         // if both i and j are at the same location and chars are same then simply increment both pointers
         if(i < s1.length && j < s2.length && diff == 0 && s1[i] == s2[j]) {
             if(helper(s1, s2, i+1, j+1, diff, dp)) {
                 return dp[i][j][diff+1000] = true;
             }
         }

         // if s1[i] is literal and diff > 0 then increment i and decrement diff by 1
         if(i < s1.length && !Character.isDigit(s1[i]) && diff > 0 && helper(s1, s2, i+1, j, diff-1, dp)) {
             return dp[i][j][diff+1000] = true;
         }

         // if s2[j] is literal and diff < 0 then increment j and increment diff by 1
         // as we are done with the current jth char
         if(j < s2.length && !Character.isDigit(s2[j]) && diff < 0 && helper(s1, s2, i, j+1, diff+1, dp)) {
             return dp[i][j][diff+1000] = true;
         }

         // wildcard matching in s1
         // if s1 contains l123
         // then need to check with val as 1 then val as 12 and val as 123
         for(int k = i, val = 0; k < i + 4 && k < s1.length && Character.isDigit(s1[k]); k++) {
             val = val * 10 + s1[k] -'0';
             if(helper(s1, s2, k+1, j, diff-val, dp)) {
                 return dp[i][j][diff+1000] = true;
             }
         }

         // wildcard matching in s2
         // if s2 contains l123
         // then need to check with val as 1 then val as 12 and val as 123
         for(int k = j, val = 0; k < j + 4 && k < s2.length && Character.isDigit(s2[k]); k++) {
             val = val * 10 + s2[k] -'0';
             if(helper(s1, s2, i, k+1, diff+val, dp)) {
                 return dp[i][j][diff+1000] = true;
             }
         }

         return dp[i][j][diff+1000] = false;
     }
}