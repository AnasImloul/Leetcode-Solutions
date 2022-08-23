// Runtime: 9 ms (Top 61.84%) | Memory: 42.7 MB (Top 63.49%)
class Solution {
        public int distinctSubseqII(String s) {
            int mod = (int)1e9+7;
            //For storing the last occurred index of a character.
            Integer li[] = new Integer[26];
            int n = s.length();
            int[] dp = new int[n+1];
            //one empty string possible for a string of length 0.
            dp[0]=1;
            char[] c = s.toCharArray();
            for(int i=1;i<=n;i++){
                //If the character is first occurred then 2 cases
                //Case 1 : we will not concat the character with previous subsequences
                //Case 2 : we will concat it.
                //Therefore, we multiply 2 with previous count.
                int curr = (2 * (dp[i - 1] % mod)) % mod;
                //Getting the int index from char for checking the previous occurrence in li[]
                int idx=c[i-1]-'a';
                //If previously occurred then we have to subtract the subsequences which are made
                //till li[idx-1] because they would be duplicated and counted twice unnecessarily
                if(li[idx]!=null) dp[i]=(curr -dp[li[idx]-1] +mod)%mod;
                else dp[i]= curr;
                li[idx]=i;
            }
            //Doing -1 because we don't have to count the empty string.
            return dp[n]-1;
        }
    }