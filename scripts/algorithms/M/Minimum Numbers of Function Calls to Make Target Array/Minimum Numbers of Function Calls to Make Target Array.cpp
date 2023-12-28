// Runtime: 61 ms (Top 41.75%) | Memory: 25.60 MB (Top 89.32%)

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        while(true) {
            bool largerThan1 = false;
            bool allzero = true;
            for(auto &n : nums) {
                if(n == 0) continue;
                allzero = false;
                if(n > 1) largerThan1 = true;
                ans += n % 2;
                n /= 2;
            }
            ans += largerThan1; //we should do division if some element is larger than 1.
            if(allzero) break;
        }
        return ans;
    }
};

