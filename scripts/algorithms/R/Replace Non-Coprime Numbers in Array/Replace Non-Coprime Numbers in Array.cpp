// Runtime: 458 ms (Top 15.39%) | Memory: 120.9 MB (Top 73.95%)
class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> res;
        for (auto num : nums) {
            while (!res.empty() && gcd(res.back(), num) > 1) {
                num = lcm(res.back(), num);
                res.pop_back();
            }
            res.push_back(num);
        }
        return res;
    }
};