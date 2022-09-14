// Runtime: 5 ms (Top 17.94%) | Memory: 6.2 MB (Top 15.94%)
class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> sol;
        sol.push_back(1);
        for(int i = 2; i <= n / 2; i++) {
            if(n % i == 0) sol.push_back(i);
        }
        if(n != 1) sol.push_back(n);
        if(k > sol.size()) return -1;
        return sol[k - 1];
    }
};