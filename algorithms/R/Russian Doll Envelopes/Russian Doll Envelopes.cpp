class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), [](auto &l, auto &r)
             {
                return l[0] == r[0] ? l[1] > r[1] : l[0] < r[0]; 
             });
        int len = 0;
        for(auto& cur: envelopes)
        {
            if(len==0 || envelopes[len-1][1] < cur[1])
                envelopes[len++] = cur;
            else
                *lower_bound(envelopes.begin(), envelopes.begin()+ len, cur, [](auto &l, auto &r)
                             {
                                 return l[1] < r[1];
                             }) = cur;
        }
        return len;
    }
};
