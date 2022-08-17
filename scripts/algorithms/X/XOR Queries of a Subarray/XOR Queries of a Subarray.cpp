class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> prefix(arr.size()+1),ans;
        int zor = 0;
        prefix[0] = 0;
        for(int i=0;i<arr.size();i++){
            zor ^= arr[i];
            prefix[i+1] = zor;
        }
        for(auto i : queries)
            ans.push_back(prefix[i[1]+1] ^ prefix[i[0]]);
        return ans;
    }
};
