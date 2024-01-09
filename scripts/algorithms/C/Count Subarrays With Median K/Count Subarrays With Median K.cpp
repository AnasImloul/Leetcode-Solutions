// Runtime: 84 ms (Top 67.92%) | Memory: 50.20 MB (Top 84.91%)

class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int n = nums.size();
        int less = 0, great = 0;
        int pivot = -1;
        for(int i=0; i<n; ++i) {
            if(nums[i] == k) {
                pivot = i;
                break;
            }
        }
        
        for(int i=pivot; i<n; ++i) {
            if(nums[i] > k) great++;
            else if(nums[i] < k) less++;
            int key = great-less;
            if(m.find(key) != m.end()) m[key]++;
            else m.insert({key, 1});
        }
        
        int count = 0;
        less=great=0;
        for(int i=pivot; i>=0; --i) {
            if(nums[i] > k) great++;
            else if(nums[i] < k) less++;
            int key = less-great;
            if(m.find(key) != m.end()) count += m[key];
            if(m.find(key+1) != m.end()) count += m[key+1];
        }
        
        return count;
    }
};
