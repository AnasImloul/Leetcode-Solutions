typedef pair<int,pair<int,int>> pii;

class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n=passingFees.size();

	//state of dp(i,j) : stores the min cost to reach city 'i' in 'j' max time;
    int dp[n][maxTime+1];
      
		
		//without using another array for time will result in TLE since it will explore more paths, hence 
		//using another array that stores the min time the city was discovered. This improves the TC to a 
		//huge extent as it prunes some path.
		
        int ttime[n];
        for(int i=0;i<n;i++){
            ttime[i]=INT_MAX;
            for(int j=0;j<=maxTime;j++){
                dp[i][j]=INT_MAX;
            }
        }
        ttime[0]=0;
        dp[0][0]=passingFees[0];
        
        vector<vector<int>>adj[n];
        for(auto x:edges){
            adj[x[0]].push_back({x[1],x[2]});
            adj[x[1]].push_back({x[0],x[2]});
        }
        
		// first priority is to minimise the cost associated with the path, {cost, city, time}
        priority_queue<pii,vector<pii>,greater<pii>>minHeap;
        minHeap.push({passingFees[0],{0,0}});
        
        while(!minHeap.empty()){
            auto top=minHeap.top();
            minHeap.pop();
           
		   int u=top.second.first; 
            int time=top.second.second;
            int cost=top.first;

			if(u==n-1)return cost;

			ttime[u]=time;
            
            for(auto x:adj[u]){
			// this is the pruning part, where we are only exploring paths that can be reached earlier than 
			//the time already required.
                if(time+x[1]<ttime[x[0]]){
                    if(time+x[1]<=maxTime){
					//now we are checking if the cost to reach the neighbor is less than the already minimum 
					//cost, denoted by dp[x[0]][time+x[1]], denoting min cost to reach x[0] in 'time+x[1]' max 
					//time.
                        if(cost+passingFees[x[0]]<dp[x[0]][time+x[1]] ){
                            dp[x[0]][time+x[1]]=cost+passingFees[x[0]];
                            ttime[x[0]]=time+x[1];
                            minHeap.push({dp[x[0]][time+x[1]],{x[0],time+x[1]}});
                        }
                    }
                }
            }
        }
        return -1;
    }
};
