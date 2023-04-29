class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int>ind(n,0);
        
        for(auto it:roads)
        {
            ind[it[0]]++;
            ind[it[1]]++;
        }
        
        priority_queue<long long> pq;
        long long val = n,ans=0;
        
        for(int i=0;i<n;i++)
            pq.push(ind[i]);
        
        while(!pq.empty())
        {
            ans += pq.top() * val;
            val--;
            pq.pop();
        }
        return ans;
    }
};