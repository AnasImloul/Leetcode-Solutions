
class Solution {
public:
    vector<vector<string>> dp ;
    string largestNumber(vector<int>& cost, int target) {
        dp.resize(10,vector<string>(target+1,"-1"));
        return solve(cost,0,target) ;
    }
    
    string solve(vector<int>& cost,int idx,int target){
        if(!target) return "";
        if(target < 0 || idx >= size(cost)) return "0"; 
        
        if(dp[idx][target]!="-1") return dp[idx][target];
        
        string a = to_string(idx+1) + solve(cost,0,target-cost[idx]);
        string b = solve(cost,idx+1,target);
        
        return dp[idx][target] = a.back() == '0' ? b : b.back() == '0' ? a : size(a) == size(b) ? max(a,b) : size(a) > size(b) ? a : b ;
    }
};

