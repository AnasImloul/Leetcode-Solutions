class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>>ans;
        unordered_map<int,vector<int>> store;
        
        for(int i=0;i<groupSizes.size();i++){
            if(store[groupSizes[i]].size()==groupSizes[i]){
               ans.push_back(store[groupSizes[i]]) ;
                store[groupSizes[i]].clear();
                }
            store[groupSizes[i]].push_back(i);}
        
        for(auto &x:store){
            ans.push_back(x.second);}
        return ans;     
    }
};
