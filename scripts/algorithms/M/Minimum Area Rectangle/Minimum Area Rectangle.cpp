// Runtime: 2865 ms (Top 5.1%) | Memory: 612.86 MB (Top 5.1%)

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int, unordered_set<int>> pts;
        for(auto p : points)
        {
            pts[p[0]].insert(p[1]);
        }
        
        int minArea = INT_MAX;
        int n = points.size();
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                auto p1 = points[i];
                auto p2 = points[j];
                if(pts[p1[0]].size()<2 || pts[p2[0]].size()<2) continue; // added to avoid extra loop
                if(p1[0]!=p2[0] && p1[1]!=p2[1]){
                    if(pts[p1[0]].count(p2[1])>0 && pts[p2[0]].count(p1[1])>0) {
                        minArea = min(minArea, (abs(p1[0]-p2[0]) * abs(p1[1]-p2[1])) );
                    }
                }
                
            }
        }
        return minArea == INT_MAX ? 0 : minArea;
    }
};