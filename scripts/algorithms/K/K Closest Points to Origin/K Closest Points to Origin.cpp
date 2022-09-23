// Runtime: 470 ms (Top 43.73%) | Memory: 66.6 MB (Top 60.32%)
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k)
    {
        //max heap
        priority_queue<pair<int,pair<int,int>>> pq;//first integer is distance(no need for sq root as comparison is same and next part of pair is coordinate
        int n= points.size();
        for(int i=0;i<n;i++)
        {
            int dist=(points[i][0]*points[i][0]+points[i][1]*points[i][1]);
            pq.push({dist, {points[i][0],points[i][1]}});
            if(pq.size()>k)
                pq.pop();
        }
        vector<vector<int>> ans;
        while(!pq.empty())
        {
            vector<int> temp={(pq.top().second.first),pq.top().second.second};
            ans.push_back(temp);
            pq.pop();
        }
        return ans;
    }
};
