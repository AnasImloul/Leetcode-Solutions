class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> output;
        int n = intervals.size();
        int i = 0;
        while(i < n){
            if(newInterval[1] < intervals[i][0]){
                output.push_back(newInterval);
                while(i < n){
                    output.push_back(intervals[i]);
                    i++;
                }
                return output;
            }
            else if(newInterval[0] > intervals[i][1]){
                output.push_back(intervals[i]);
                i++;
            }
            else{
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
                i++;
            }
        }
        output.push_back(newInterval);//think about it
        return output;
    }
};