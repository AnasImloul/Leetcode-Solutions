// Runtime: 920 ms (Top 16.77%) | Memory: 89.8 MB (Top 27.22%)

class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b)
    {
        return a[1]<b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),cmp);
        //burst the first ballon at least
        int arrow=1;
        int end=points[0][1];
        for(int i=1;i<points.size();i++)
        {
            //start time of other interval is greater than current end time means we need one more arrow for bursting it
            if(points[i][0]>end)
            {
                arrow++;
                end=points[i][1];
            }
        }
        return arrow;
    }
};