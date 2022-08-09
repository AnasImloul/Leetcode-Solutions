class Solution {
public:
     
    int ans;    
    unordered_map<int,unordered_map<int,unordered_map<int,int>>> dp;
    
    int Solve(vector<vector<int>>& events, int start, int n, int k, int endtime){
        if(k == 0 || start == n){
            return 0;
        }
        
        if(dp.find(start) != dp.end() && dp[start].find(k) != dp[start].end() && dp[start][k].find(endtime) != dp[start][k].end()){
        
            return dp[start][k][endtime];
        }
        int t1 = 0;
        if(events[start][0] > endtime){
            t1 = events[start][2] + Solve(events, start+1, n, k-1, events[start][1]);
        }
        
        int t2 = Solve(events,start+1,n,k,endtime);
        
        dp[start][k][endtime] = max(t1,t2);
       // cout<< dp[start][k][endtime]<<endl;
     
        return dp[start][k][endtime];
        
    }
    int maxValue(vector<vector<int>>& events, int k) {
        
        dp.clear();
     
        // sort according to start time
        sort(events.begin(), events.end(),[](vector<int> &a,vector<int> &b){
            return a[0] < b[0];
        });
        
    return Solve(events,0,events.size(),k,0);
    
    }
};
