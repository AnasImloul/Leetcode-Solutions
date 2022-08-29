// Runtime: 33 ms (Top 28.06%) | Memory: 10.9 MB (Top 28.46%)
class Solution {
typedef pair<int, int> pd;
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int seat=0;
        priority_queue<pd, vector<pd>, greater<pd>>pq;
        for(auto it : trips)
        {
              pq.push({it[1], +it[0]});
              pq.push({it[2], -it[0]});
        }
        while(!pq.empty())
        {
            // cout<<pq.top().first<<" "<<pq.top().second<<endl;
            // cout<<"seat-"<<seat<<endl;
            seat+=pq.top().second;
            if(seat>capacity) return false;
            pq.pop();
        }
        return true;
    }
};