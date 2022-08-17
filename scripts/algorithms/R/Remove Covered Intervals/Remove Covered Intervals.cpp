class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) 
    {
        int cnt = 0, last = INT_MIN;
        sort(intervals.begin(), intervals.end(), 
             [] (const vector<int>& v1, const vector<int>& v2) { 
                 if(v1[0] != v2[0]) return v1[0] < v2[0];
                 else return v1[1] > v2[1];
        });

        for(int i=0; i<intervals.size(); i++)
        {
            if(intervals[i][1] <= last) ++cnt;
            
            if(intervals[i][1] > last) last = intervals[i][1];
        }
        
        return intervals.size()-cnt;
    }
}; 
