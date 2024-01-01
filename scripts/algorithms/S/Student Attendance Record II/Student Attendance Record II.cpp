// Runtime: 71 ms (Top 84.38%) | Memory: 24.60 MB (Top 56.83%)

class Solution {
public:
    const int mod = 1e9 + 7;
    
    int add(int a, int b){
        return (a%mod + b%mod)%mod;
    }
    
    int sub(int a, int b){
        return (a%mod - b%mod + mod)%mod;
    }
    
    int mul(int a, int b){
        return (a%mod * 1ll * b%mod)%mod;
    }
    
    int checkRecord(int n) {
        if(n == 1) return 3;
     
        vector<int>PorL(n + 1); /*for strings ending with 'P' or 'L' and no 'A' is present*/
        vector<int>P(n + 1); /* for strings ending with 'P' and no 'A' is present */

        // for 0 length strings only 1 option can be there (base case)
        P[0] = 1, PorL[0] = 1;
        
        /*for 1 length strings*/
        P[1] = 1; /*can end with 'P' only */
        PorL[1] = 2; /*can end with either 'P' or 'L' */

        /*for 2 length strings*/
        P[2] = PorL[1]; /*ending with 'P' so the previous string can end with 'P' or 'L' */
        PorL[2] = P[2] + P[1] + P[0]; /*either current char can be 'P' or 'L' or last 2 chars can be 'L' i.e "LL" */
        
        for(int i = 3;i<=n;i++){
            P[i] = PorL[i - 1] % mod;
            PorL[i] = add(P[i], add(P[i - 1], P[i - 2]));
        }
        
        int ans = PorL[n]; /*if we have no 'A'*/
        /*since we can have only 1 'A' lets try to insert at each position */
        for(int i = 1;i<=n;i++){
            /*if we insert 'A' at ith position */
            int leftLength = i - 1; /*the length of the string to the left of i*/
            int rightLength = n - i; /*the length of the string to the right of i*/
            ans = add(ans, mul(PorL[leftLength], PorL[rightLength]));
        }
        return ans;
        
    }
};
