// Runtime: 893 ms (Top 18.17%) | Memory: 80.1 MB (Top 33.41%)
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int res=0;
        int m=0;
        for(auto x:events)
            m=max(m,x[1]);

        sort(events.begin(),events.end());
        int j=0;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=1;i<=m;i++)
        {
            while(!pq.empty() && pq.top()<i)// end day is less than the current day
                pq.pop();

            while(j<events.size() && events[j][0]==i)// put all events start at day i
                pq.push(events[j++][1]);

            if(!pq.empty())// we can attend an event today
            {
                pq.pop();// remove the event
                res++;// count that event
            }
        }
        return res;
    }
};