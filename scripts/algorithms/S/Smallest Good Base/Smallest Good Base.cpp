// Runtime: 3 ms (Top 73.58%) | Memory: 6.3 MB (Top 42.92%)
class Solution {
public:
    string smallestGoodBase(string n) {
        string ans;
        long long nn = stol(n);

        // since n<1E18, the largest possible number of digits is 62.
        for (int i=62;i>2;i--){
            // Since n = k^i-1 + k^i-2 + ... + k + 1, a good estimate of k is pow(n, 1/(i-1))
            long long k = pow(nn,1.0/(i-1));
            if (k==1) continue;

            long long sum = 1,kk=1;

            // Calculate the sum of i-ones base k. Although we have a direct approach using the formula of geometric series sum, n = (k^i - 1)/(k-1), but this approach has two issues: 1) k^i may be larger than LONG_MAX; 2) the pow() function returns a float number which only has 15 decimal digits precision, and not suitable for calculation of 18 digit int.
            for (int j=1;j<i;j++){
                kk*=k;
                sum+=kk;
            }

            if (sum==nn) return to_string(k);
        }

        // We always have a trivial solution n-1. The number is 2 digits base (n-1);
        return to_string(nn-1);
    }
};