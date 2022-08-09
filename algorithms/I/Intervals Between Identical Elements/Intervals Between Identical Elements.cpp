class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        int size=arr.size();
        vector<long long>pre(size,0),suf(size,0),ans(size,0);
        unordered_map<int,vector<int>>mp;
        
        // store index of the same elements.
        for(int i=0;i<size;i++)
            mp[arr[i]].push_back(i);
       //  prefix will store the sum of absolute diff. from the starting index of current element to the current index.
        // pre[cur index]=pre[prev index]+ number of same elements before cur element * abs diff of cur element pos and pre element pos
        for(auto &p:mp){
            auto vec=p.second;
            for(int i=1;i<vec.size();i++)
                pre[vec[i]]=  pre[vec[i-1]]+  i*(long)(vec[i]-vec[i-1]);
        }
       // suffix will store the sum of absolute diff. from the ending index of current element to the current index.
        // same formula as above but in reverse order
        for(auto &p:mp){
            auto vec=p.second;
            for(int i=vec.size()-2;i>=0;i--)
                suf[vec[i]]=  suf[vec[i+1]] + long(vec.size()-1-i) * (long)(vec[i+1]-vec[i]);
        }
        for(int i=0;i<size;i++)
            ans[i]+=(pre[i]+suf[i]);
        return ans;
    }
};
