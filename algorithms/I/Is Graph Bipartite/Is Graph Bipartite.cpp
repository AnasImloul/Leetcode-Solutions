class Solution {
public:
	bool isBipartite(int node, vector<int>&color, vector<vector<int>>& graph)
	{
		if(color[node]==-1)    color[node] = 1;
		for(auto it:graph[node])
		{
			if(color[it]==-1)
			{
				color[it] = !color[node];
				if(!isBipartite(it,color,graph))    
					return false;
			}
			else if(color[it]==color[node])    
				return false;
		}
		return true;
	}
	bool isBipartite(vector<vector<int>>& graph) {
		int n = graph.size();
		vector<int> color(n,-1);
		for(int i=0;i<n;i++)
			if(color[i] == -1)
				if(!isBipartite(i,color,graph))     
					return false;
		return true;
	}
};