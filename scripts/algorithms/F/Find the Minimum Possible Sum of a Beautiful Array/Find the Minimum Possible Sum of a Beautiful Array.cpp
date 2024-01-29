// Runtime: 0 ms (Top 100.0%) | Memory: 7.40 MB (Top 11.51%)

class Solution {
public:
  int mod=1e9+7;
  int minimumPossibleSum(long long n, long long target) {

    long long ans = 0;
    // this variable holds the numbers we can take which are below target
    long long below_target=target/2;

    //If n is below below_target, all n numbers can be taken
    if(n<=below_target) return (n*(n+1))/2;

    //else take all possible below_target numbers sum
    ans+=((below_target*(below_target+1))/2);

    //reduce this count(taken/summed up above) from n;
    n-=(below_target);

    //shift n to target, so that will be adding from target onwards
    n+=(target-1);

    // take the sum. ie, in the range [target,new_n]
    ans+=((n*(n+1))/2)-(((target-1)*target)/2);

    return ans%mod;
  }
};
