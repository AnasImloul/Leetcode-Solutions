class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size();
        vector <vector <int>> graph(n);
        vector <int> time(n, -1);
        
        for(auto x: edges) { // create adjacency list
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        
        queue <int> q;
        q.push(0);
        time[0] = 0;
        while(q.size()) {
            int node = q.front();
            q.pop();
            
            for(auto child: graph[node]) {
                if(time[child] == -1) { // if not visited.
                    time[child] = time[node] + 1; // calc time for child node
                    q.push(child);
                }
            }
        }
        
        int res = 0;
        for(int i = 1; i<n; i++) {
            int extraPayload = (time[i]*2 - 1)/patience[i]; 
			// extra number of payload before the first message arrive back to data server.
			// since a data server can only send a message before first message arrives back."
			// and first message arrives at time[i]*2. so "(time[i]*2-1)"
			
            int lastOut = extraPayload * patience[i]; // find the last time when a data server sends a message
            int lastIn = lastOut + time[i]*2; // this is the result for current data server
			
            res = max(res, lastIn);
        }
		
		// at "res" time the last message has arrived at one of the data servers.
		// so at res+1 no message will be passing between servers.
		
        return res+1;
    }
};
