#define x1 points[i][0]
#define y1 points[i][1]
#define x2 points[j][0]
#define y2 points[j][1]
#define x3 points[k][0]
#define y3 points[k][1]

class Solution {
public:
  double minAreaFreeRect(vector<vector<int>>& points) {
    int ans = INT_MAX;
    sort(points.begin(),points.end());
    set<pair<int,int>>st;
    for(auto &p: points) st.insert({p[0], p[1]});
    
    for(int i = 0; i != points.size() && ans != 1; i++)
      for(int j = i+1; j != points.size() && ans != 1; j++)
        for(int k = j+1; k != points.size() && ans != 1; k++)
          if( (x1-x2)*(x2-x3)+(y1-y2)*(y2-y3) == 0 && st.count({x1+x3-x2, y1+y3-y2}))
          ans = min(ans, abs( (y1-y2)*(x3-x2) - (x1-x2)*(y3-y2)));
         
    return ans == INT_MAX ? 0.0 : double(ans);
  }
};
