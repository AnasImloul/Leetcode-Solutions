class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<pair<int,int>> v(n+1,{0,0});
        
        for(auto i : trust){
            v[i[0]].first++;
            v[i[1]].second++;
        }
        
        int ans = -1;
        

        for(int i=1;i<=n;i++){
            auto p = v[i];
            if(p.first == 0 && p.second == n-1){
                ans = i;
                break;
            }
        }
        
        return ans;
    }
};
