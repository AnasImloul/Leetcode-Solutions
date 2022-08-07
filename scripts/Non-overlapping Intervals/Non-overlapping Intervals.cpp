class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        priority_queue<pair<int, int> > pq;
        int ans = 0;
        //maxheap by ending time
        pq.push({intervals[0][1], intervals[0][0]});
        for(int i=1;i<intervals.size();i++){
            //if start of this interval is overlapping with max end time of some prev interval
            if(pq.top().first > intervals[i][0]){
                //remove one with max ending time
                if(pq.top().first > intervals[i][1]){
                    pq.pop();
                    pq.push({intervals[i][1], intervals[i][0]});
                }
                //update ans
                ans++;
            }
            else{
                //push current interval.
                pq.push({intervals[i][1], intervals[i][0]});
            }
        }
        return ans;
    }
};
