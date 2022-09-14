// Runtime: 753 ms (Top 12.23%) | Memory: 149.9 MB (Top 18.31%)
class Solution {
public:
    void solve(vector<int> arr,vector<vector<int>> &ans,vector<int> &temp,int k,int x){
        if(temp.size()==k){
            ans.push_back(temp);
            return;
        }
        if(x>=arr.size()) return ;
        for(int i = x;i<arr.size();i++){
            temp.push_back(arr[i]);
            solve(arr,ans,temp,k,i+1);
            temp.pop_back();
        }
}
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<int> arr;
        for(int i = 1;i<=n;i++) arr.push_back(i);
        solve(arr,ans,temp,k,0);
        return ans;
    }
};