class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        map<int,vector<int>> mp; 
        // map the 1st element in pieces[i] to pieces[i]
        for(auto p:pieces) 
            mp[p[0]] = p;
        vector<int> result;
        for(auto a:arr) {
            if(mp.find(a)!=mp.end()) 
                result.insert(result.end(),mp[a].begin(),mp[a].end());
        }
        return result ==arr;
    }
};
