class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        
        int n = arr.size();
        
        unordered_map<int,int>mp;
        multiset<int>s;
        int ans = 1;
        
        for(int i=0;i<n;i++)
        {
            int req = arr[i] - difference;
            auto it = s.find(req);
            s.insert(arr[i]);
            
            if(it == s.end())
            {
                continue;    
            }
            else
            {
                mp[arr[i]] = mp[req] + 1;
                ans = max(ans,mp[arr[i]] + 1);
            }
        }
        
        return ans;
    }
};