class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
       vector<vector<int>> v;
        int n = queries.size();
        for(int i = 0; i < n; i++){
            v.push_back({queries[i],i});
        }
        sort(v.begin(),v.end());
        sort(items.begin(),items.end());
        vector<int> ans(n);
        int j=0;
        n = items.size();
        int mx = 0;
        for(auto &i: v){
            while(j<n && items[j][0]<=i[0]){
                mx = max(mx,items[j][1]);
                j++;
            }
            ans[i[1]] = mx;
        }
        return ans;
    }
};