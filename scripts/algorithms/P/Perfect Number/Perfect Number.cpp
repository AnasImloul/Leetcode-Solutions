// Runtime: 0 ms (Top 100.00%) | Memory: 5.9 MB (Top 68.45%)

class Solution {
public:
    bool checkPerfectNumber(int num) {
    // we are initialising sum with 1 instead of 0 because 1 will be divisor of every number
        int sum=1;
        for(int i=2; i<sqrt(num); i++){
            if(num%i==0){
            // it checks if both are same factors, for ex, if num=9, i=3, num/i is also equal to 3. It is done so that repeated factors aren't added.
                if(i==num/i){
                    sum += i;
                }
                else{
                // we are adding n/i because since we are running the loop for sqrt(num), we will be missing divisors >sqrt(num) so tto include that factor we'll add num/i; for ex if we have 64 as number than 8 is sqrt but 16 and 32 also divides 64 but our loop won't consider that case; so we are adding num/i, which means with 2 we are adding 32 and with 4 we are adding 16.
                    sum += i + num/i;
                }
            }
        }
        if(sum==num && num!=1){
            return true;
        }
        return false;
    }
};