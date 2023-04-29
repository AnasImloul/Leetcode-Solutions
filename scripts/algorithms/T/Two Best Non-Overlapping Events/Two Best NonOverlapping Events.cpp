
#define ipair pair<int,int>
class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
	
        //sort based on smaller start time
       sort(events.begin(), events.end());
        
        int mx = 0, ans = 0, n = events.size();
        priority_queue<ipair, vector<ipair>, greater<>> pq;
        // pq conatins {event_endtime , even_value}
        // for every event check the max-value of earlier events whose 
        // deadline is less than start time of curr event
        for(int i=0; i<n; i++)
        {
            while(!pq.empty() && pq.top().first < events[i][0])
                mx = max(mx, pq.top().second), pq.pop();
            
            ans = max(ans, mx+events[i][2]);
            pq.push({events[i][1], events[i][2]});
        }
        
        return ans;
    }
};
