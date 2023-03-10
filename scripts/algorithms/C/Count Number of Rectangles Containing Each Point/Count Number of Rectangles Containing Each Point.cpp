class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        
        int i, count, ind, x, y, n = rectangles.size();
        
        vector<int> ans;
        vector<vector<int>> heights(101);
        
        for(auto rect : rectangles)
            heights[rect[1]].push_back(rect[0]);
        
        for(i=0;i<101;i++)
            sort(heights[i].begin(), heights[i].end());
        
        for(auto point : points)
        {
            count = 0;
            x = point[0];
            y = point[1];
            for(i=y;i<101;i++)
            {
                ind = lower_bound(heights[i].begin(), heights[i].end(), x) - heights[i].begin();
                count += (heights[i].size() - ind);
            }
            ans.push_back(count);
        }
        return ans;
    }
};