// Runtime: 545 ms (Top 77.81%) | Memory: 132.6 MB (Top 61.42%)
class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> adjList(n);
        vector<int> inDegree(n),cTime(n,0);

        for(auto &r:relations) { // Create adjacency list and in degree count vectors.
            adjList[r[0]-1].push_back(r[1]-1);
            inDegree[r[1]-1]++;
        }
        queue<pair<int,int>> q;

        for(int i=0;i<n;i++) // Get all nodes with in-degree=0 and store add them to the queue.
            if(!inDegree[i])
                q.push({i,0});

        while(!q.empty()) {
            auto [node,t]=q.front(); // Process node `node`.
            q.pop();

            // Completion time of the current node the time when the processing started `t`
            // (Max time at which prerequisutes completed) + the time taken to process it `time[node]`.
            int completionTime=t+time[node];
            cTime[node]=completionTime; // Store the final completion time of the node `node`.

            for(int &n:adjList[node]) {
                // Update the intermediate completion time of the child node `n`.
                // This means that node `n` would start processing at least at `cTime[n]`.
                cTime[n]=max(cTime[n],completionTime);

                if(!--inDegree[n]) // Add the node with in-degree=0 to the queue.
                    q.push({n,cTime[n]});
            }
        }
        // Return the maximum time it took for a node/course to complete as our result.
        return *max_element(cTime.begin(),cTime.end());
    }
};