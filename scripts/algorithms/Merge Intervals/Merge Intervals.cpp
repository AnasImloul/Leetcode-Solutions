class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        int i=0;
        while(i<=intervals.size()-1){
            int start=intervals[i][0];
            int end=intervals[i][1];
            while(i<intervals.size()-1 && end>=intervals[i+1][0]){
                i++;
                if(end<intervals[i][1]) end=intervals[i][1];
            }
            i++;
            res.push_back({start, end});
        }
        return res;
    }
};
