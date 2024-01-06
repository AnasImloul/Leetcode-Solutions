// Runtime: 473 ms (Top 95.15%) | Memory: 188.20 MB (Top 79.11%)

class Solution {
public:
    int find(vector<int>& nums,int i){
        if(nums[i]==-1) return i;
        else return nums[i] = find(nums,nums[i]);
    }
    void union_(vector<int>& nums,int x,int y){
        int i = find(nums,x), j = find(nums,y);
        if(i!=j){
            if(i<j) nums[j] = i;
            else nums[i] = j;
        }
    }
    int numberOfGoodPaths(vector<int>& val, vector<vector<int>>& arr) {
        int n = val.size();
        vector<vector<int>> nums(n+1);
		
        for(int i = 0; i<arr.size();++i){
            int a = arr[i][0], b = arr[i][1];
            if(val[a]>=val[b]) nums[a].push_back(b);
            else if(val[a]<=val[b]) nums[b].push_back(a);
        }
		
        map<int,vector<int>> mp;
        vector<int> dp(n+1,-1);
        for(int i = 0; i<n;++i) mp[val[i]].push_back(i);
		
        int re = 0;
        for(auto it = mp.begin(); it!=mp.end();++it){
            vector<int> &temp = it->second;
            map<int,int> st;
            for(int i = 0; i<temp.size();++i){
                int j = temp[i];
                for(int k = 0; k<nums[j].size();++k) union_(dp,j,nums[j][k]);  //union node j with all adjacent node having value no greater than current value
            }
            for(int i = 0; i<temp.size();++i){
                int j = temp[i];
                st[find(dp,j)]++;  // take count of all parent node
            }
            for(auto it = st.begin(); it!=st.end();++it) re+= it->second*(it->second-1)/2;
        }
		
        return re+n;
    }
};
