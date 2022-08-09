class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        
        int n(size(nums)), res(0);
        sort(begin(nums), end(nums));
    
        for (int start=0, next=0; start<n;) {
            while (next<n and nums[next]-nums[start] <= k) next++;            
            start = next;
            res++;
        }
        return res;
    }
};
