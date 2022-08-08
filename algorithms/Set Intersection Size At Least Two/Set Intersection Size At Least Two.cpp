class Solution {
public:
    
    // sort wrt. end value
    
    static bool compare(vector<int>& a, vector<int>& b)
    {
        if(a[1] == b[1])
            return a[0] < b[0];
        else
            return a[1] < b[1];
    }
    
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        
        int n = intervals.size();
        
        // sort the array
        
        sort(intervals.begin(), intervals.end(), compare);
        
        vector<int> res;
        
        res.push_back(intervals[0][1] - 1);
        
        res.push_back(intervals[0][1]);
        
        for(int i = 1; i < n; i++)
        {
            int start = intervals[i][0];
            
            int end = intervals[i][1];
            
            if(start > res.back())
            {
                res.push_back(end - 1);
                
                res.push_back(end);
            }
            else if(start == res.back())
            {
                res.push_back(end);
            }
            else if(start > res[res.size() - 2])
            {
                res.push_back(end);
            }
        }
        
        return res.size();
    }
};
