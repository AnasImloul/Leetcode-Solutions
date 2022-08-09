class Solution {
public:
    int validSubarraySize(vector<int>& nums, int threshold) {
        int n = nums.size();
        vector<long long> lr(n, n), rl(n, -1);
        
        vector<int> s;
        for(int i = 0; i < n; ++i) {
            while(!s.empty() and nums[i] < nums[s.back()]) {
                lr[s.back()] = i;
                s.pop_back();
            }
            s.push_back(i);
        }
        s.clear();
        for(int i = n - 1; ~i; --i) {
            while(!s.empty() and nums[i] < nums[s.back()]) {
                rl[s.back()] = i;
                s.pop_back();
            }
            s.push_back(i);
        }
        
        for(int i = 0; i < n; ++i) {
            long long length = lr[i] - rl[i] - 1;
            if(1LL * nums[i] * length > threshold) return length;
        }
        
        return -1;
    }
};
// please upvote if you like
