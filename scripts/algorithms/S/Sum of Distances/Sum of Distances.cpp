// Runtime: 159 ms (Top 81.54%) | Memory: 109.80 MB (Top 66.77%)

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        int n = nums.size();        
        vector<long long> ans(n, 0);
        
        for(int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        
        for(auto& itr: mp) {
            int m = itr.second.size();
            
            if(m == 1) continue;
            
            vector<long long> left(m), right(m);
            
            left[0] = 0;
            for(int i = 1; i < m; i++) {
                left[i] = left[i-1] + (long long)(itr.second[i] - itr.second[i-1]) * i;
            }
            
            right[m-1] = 0;
            for(int i = m-2; i >= 0; i--) {
                right[i] = right[i+1] + (long long)(itr.second[i+1] - itr.second[i]) * (m-i-1);
            }
            
            for(int i = 0; i < m; i++) {
                ans[itr.second[i]] = left[i] + right[i];
            }
        }
        
        return ans;
    }
};

