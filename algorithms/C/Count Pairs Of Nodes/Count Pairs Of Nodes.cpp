class Solution {
public:
    map<pair<int, int>, int>edgeCount;
    vector<int>degree;
    
    vector<int> countPairsHelper(vector<int>&indegree, vector<int>&queries, int n){
        vector<int>ans;
        
        // for each query, time: O(2*n) for two pointer and O(uniqueEdgesCount)
        for(int query: queries){         
            // two pointer 
            int i = 0, j = n-1, total = 0;
            while(i != j){
                if(degree[i] + degree[j] > query){
                    j--;
                }
                else{
                    total += (n-j-1);
                    i++;
                }
            }
            while(i < n){
                total += (n-i-1);
                i++;
            }
            
            
            // remove the negative contribution of edgeCount from all the pairs so far counted
            for(auto i: edgeCount){
                int u = i.first.first, v = i.first.second, w = i.second;
                // cout<<indegree[u] + indegree[v] - w<<endl;
                if(indegree[u] + indegree[v] > query && indegree[u] + indegree[v] - w <= query){
                    total -= 1;
                }
            }
            ans.push_back(total);
        }
        return ans;
    }
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
        
        vector<int>indegree(n, 0);
        for(auto edge: edges){
            int x = edge[0], y = edge[1];
            int u = min(x,y);
            int v = max(x,y);
            --u, --v;
            edgeCount[{u,v}] += 1;
            indegree[u]++;
            indegree[v]++;
        }
        
        for(int i = 0; i < n; ++i){
            degree.push_back(indegree[i]);
        }
        sort(degree.begin(), degree.end()); // sort degree to apply smart two pointer
        return countPairsHelper(indegree, queries, n);
    }
};
