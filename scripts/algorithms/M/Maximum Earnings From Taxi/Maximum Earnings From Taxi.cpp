// Runtime: 631 ms (Top 89.55%) | Memory: 99.6 MB (Top 81.24%)

class Solution {
    long long dp[100005];
    // Searching for next passenger who can sit in the car
    int binarySearch(vector<vector<int>>& rides,int val){
        int s=0,e=rides.size()-1;
        int ans=rides.size();
        while(s<=e){
            int mid = s + (e-s)/2;
            if(rides[mid][0]>=val){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }

    long long helper(int i,vector<vector<int>>& rides){
        if(i==rides.size()){
            return 0;
        }
        if(dp[i]!=-1) return dp[i];
        long long op1 = helper(i+1,rides); // We didn't pick this ith passenger
        int idx = binarySearch(rides,rides[i][1]);
        long long op2 = rides[i][1]-rides[i][0] + rides[i][2] + helper(idx,rides); // We pick this ith passenger
        return dp[i]=max(op1,op2);
    }

public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        memset(dp,-1,sizeof dp);
        sort(rides.begin(),rides.end());
        return helper(0,rides);
    }
};