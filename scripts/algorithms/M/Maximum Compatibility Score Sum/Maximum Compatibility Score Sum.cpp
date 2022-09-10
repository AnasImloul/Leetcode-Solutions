// Runtime: 189 ms (Top 59.67%) | Memory: 10 MB (Top 51.80%)
class Solution {
    // Calculating compatibility scores of ith student and jth mentor
    int cal(int i,int j,vector<vector<int>>& arr1,vector<vector<int>>& arr2){
        int cnt=0;
        for(int k=0;k<arr1[0].size();k++){
            if(arr1[i][k]==arr2[j][k]){
                cnt++;
            }
        }
        return cnt;
    }

    int helper(int i,int m,vector<vector<int>>& arr1,vector<vector<int>>& arr2,vector<bool>& vis){
        if(i==m){
            return 0;
        }
        int ans = 0;
        for(int j=0;j<m;j++){
            if(!vis[j]){
                vis[j]=1;
                ans = max(ans,cal(i,j,arr1,arr2) + helper(i+1,m,arr1,arr2,vis));
                vis[j]=0; // Backtracking
            }
        }
        return ans;
    }

public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int m = students.size();
        vector<bool> vis(m,0); // To keep track of which mentor is already paired up
        return helper(0,m,students,mentors,vis);
    }
};