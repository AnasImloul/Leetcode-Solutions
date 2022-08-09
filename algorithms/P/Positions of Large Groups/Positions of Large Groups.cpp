class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> res;
        
        int st = 0;
        int en = 1;
        
        while(en < s.size())
        {
            if(s[en] != s[st])
            {
                if(en-st >= 3)
                {
                    res.push_back({st, en-1});
                    
                }
                st = en;
                en = st+1;
            }
            else
            {
                en++;
            }
        }
        
        if(en-st >= 3)
        {
            res.push_back({st, en-1});
        }
        
        return res;
    }
};
