// Runtime: 342 ms (Top 47.2%) | Memory: 141.26 MB (Top 27.0%)

class Solution 
{
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) 
    {
        int n=vals.size();
        vector<pair<int, int>> adj[n]; //stores (ai, bi, and bi's value) here ai and bi are node connected with an edge
        
        for(int i=0; i<edges.size(); i++) //creating undirected graph with node's value
        {
            adj[edges[i][0]].push_back({edges[i][1], vals[edges[i][1]]});
            adj[edges[i][1]].push_back({edges[i][0], vals[edges[i][0]]});
        }
        
        int maxi = INT_MIN;
        vector<int> connectedNodesVals; //stores connected nodes' value 
        for(int node=0; node<n; node++)
        {
            for(auto it:adj[node]) //storing all the adjacent nodes' value
            {
                connectedNodesVals.push_back(it.second);
            }
            //sort vals in descreasing order to get top-k max vals
            sort(connectedNodesVals.begin(), connectedNodesVals.end(), greater<int>()); 
            
            int i=0, sum=vals[node];
            maxi = max(maxi, sum); //for handling single node condition & negative nodes' values 
            while(i<connectedNodesVals.size() && i<k) //calculating max star sum
            {
                sum += connectedNodesVals[i++];
                maxi = max(maxi, sum);
            }
            
            connectedNodesVals.clear(); //clear array for next node
        }
        return maxi;
        
        
    }
};