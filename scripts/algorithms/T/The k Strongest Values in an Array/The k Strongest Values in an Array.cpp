class Solution 
{
public:
    vector<int> getStrongest(vector<int>& arr, int k) 
    {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int m=arr[(n-1)/2];
        priority_queue<pair<int,int>> pq;
        for(auto it: arr)
        {
            pq.push({abs(it-m),it});
        }
        vector<int> ans;
        while(k-- && !pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};