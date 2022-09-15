// Runtime: 522 ms (Top 24.95%) | Memory: 104.9 MB (Top 77.23%)
class Solution {
public:
    //2-pointer doesnt work on neg elements
    //Using mono deque to solve sliding window
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int minsize = INT_MAX;
        vector<long> prefixsum(n,0);
        deque<int> dq;

        prefixsum[0] = nums[0];
        for(int i = 1;i<n;i++) prefixsum[i] = prefixsum[i-1] + nums[i];

        for(int i = 0;i<n;i++){
            if(prefixsum[i]>=k)
                minsize = min(minsize,i+1);

            while(!dq.empty() && prefixsum[i]-prefixsum[dq.front()]>=k){
                minsize = min(minsize,i-dq.front());
                dq.pop_front();
            }

            while(!dq.empty() && prefixsum[i]<=prefixsum[dq.back()]){
                dq.pop_back();
            }

            dq.push_back(i);
        }
        return (minsize==INT_MAX) ? -1 : minsize;
    }
};