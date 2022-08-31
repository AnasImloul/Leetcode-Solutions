// Runtime: 258 ms (Top 70.76%) | Memory: 10.2 MB (Top 70.25%)
class Solution {
public:
    int countPrimes(int n) {
        if(n == 0 || n == 1) return 0;
        vector<bool>prime(n,true);
        for(int i = 2; i*i < n; i++){
            if(prime[i]){
                for(int j = i*i; j < n; j += i){
                    prime[j] = false;
                }
            }
        }
        int cnt = 0;
        for(int i = 2; i < n; i++){
            if(prime[i]) cnt++;
        }
        return cnt;
    }
};