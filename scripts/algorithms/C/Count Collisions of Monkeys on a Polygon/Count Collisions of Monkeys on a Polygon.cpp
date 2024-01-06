// Runtime: 0 ms (Top 100.0%) | Memory: 6.30 MB (Top 73.43%)

/*


It can be seen that the answer is sum of the coefficient of the binomial expansion which is equal to 2^n - 2. 
-2 is to remove first and last 1 of the expansion.

Another way of thingk is that each of the monkey have 2 possible direction to move and there are n monkey so total 2^n ways possible.
But as two cases where all monkey moves in clock wise or in anti clock wise direction where no colision will be there, then we need to remove these two cases. So answer is 2^n - 2.

FAQ: 
1. why you have done t<0 then m+t
ans. assume mod is supposed to be 15, for n = 4, when the 2^4 is 16 and when you take mod 15, result will be 1 and further when when you subtract 2 form 1, ans will be -1 but actual answer is 16 - 2 = 14, which is smaller than 15.
So when mod value is less than 0, just add mod to your ans will give correct result.

2. Why not we are subtracting 4 from 2^n when n is even?
ans. Its actually controversial/confusing, but the example suggest that we do not need to consider this even case ( cosidering colision in air or in between when swaping accross tow points). Also the test cases are such that it passing when we return 2^n -2. May be infuture if test case updated then we might need to handle this even case as well.

*/

class Solution {
public:
    int m = 1000000007;
    long long pow2(long long n){
        if(n == 1) return 2;
        long long t = pow2(n/2);
        t = (t*t) % m;
        return (n%2)? (2*t)%m: t;
    }
    
    int monkeyMove(int n) {
        int t = pow2(n) - 2;
        return (t < 0)? m + t: t;
    }
};
