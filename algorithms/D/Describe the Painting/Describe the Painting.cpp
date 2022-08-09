typedef long long ll;

class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        vector<vector<ll> > ans;
        map<int,ll> um;
        
        for(auto s : segments){
            um[s[0]] += s[2];
            um[s[1]] -= s[2];
        }
        bool flag = false;
        pair<int,ll> prev;
        ll curr = 0;
        
        for(auto x : um){
            if(flag == false){
                prev = x;
                curr += x.second;
                flag = true;
                continue;
            }
            
            vector<ll> v = {prev.first,x.first,curr};
            prev = x;
            if(curr)
                ans.push_back(v);
            curr += x.second;
            
        }
        return ans;
    }
};
