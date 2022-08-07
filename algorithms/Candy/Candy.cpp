class Solution {
public:
    int candy(vector<int>& ratings) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int ans = 0, i;
        vector<int> store(ratings.size(), 1);
        for (i = 0; i < ratings.size()-1; i++) if(ratings[i+1] > ratings[i]) store[i+1] = store[i]+1;
        for (i = ratings.size()-1; i > 0; i--) if(ratings[i-1] > ratings[i]) store[i-1] = max(store[i-1], store[i]+1);
        for (auto i:store) ans += i;
        return ans;
    }
};
