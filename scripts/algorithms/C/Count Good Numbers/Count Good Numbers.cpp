// Runtime: 0 ms (Top 100.00%) | Memory: 5.9 MB (Top 86.69%)
// Approach :-> This is question of combination
// if n as large no....
// 0 1 2 3 4 5 6 7 8 9 10 11 . . . . . n
// 5 * 4 * 5 * 4 * 5 * 4 * 5 * 4 * 5 * 4 * 5 * 4 . . . . . n/4 times of 4 and n/4 times of 5;
//so calculate 5*4 = 20 -------> 20 * 20 * 20 * . . . . .. n/2 times
//so calcultae pow(20,n/2)
// if n is even return pow(20,n/2)
// if n is odd return 5*pow(20,n/2) beacause if n is odd then one 5 is left out
// we can easily calculate pow(x,y) in log(y) times
// durign calculation take care about mod
class Solution {
public:
    int mod = 1000000007;
    long long solve(long long val,long long pow){ // calculatin pow in log(n) time
        if(pow==0) return 1;

        if(pow%2==0){
            return solve((val*val)%mod,pow/2)%mod;
        }
        else
            return (val*solve((val*val)%mod,pow/2))%mod;

    }
    int countGoodNumbers(long long n) {
        // even means 5 options
        // odd means 4 option

        long long pow = n/2; // calculate no of times 5*4 means 20 occurs

        long long ans = solve(20,pow); // calculate power(20,pow)

        if(n%2==0){ // if n is even then 5 and 4 occur same no of time n/2
            return ans;
        }
        return ((5*ans) % mod); // if n is odd then 5 occurs n/2+1 times means one extra times so return ans*5 and don't forgot to mod
    }
};