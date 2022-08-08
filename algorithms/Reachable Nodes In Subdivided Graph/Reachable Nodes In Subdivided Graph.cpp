  class Solution {
  public:
  int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
  const int INF = 1e8;
  vector<vector<pair<int,int>> g(n);
  for(auto i: edges){
  g[i[0]].push_back({i[1],i[2]});
  g[i[1]].push_back({i[0],i[2]});
  }
  
  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
  pq.push({0, 0}); //distance,node
  vector<int> d(n, INF);
  d[0] = 0;
  
  while(!pq.empty()){
       int dist = pq.top().first;
       int node = pq.top().second;
       pq.pop();
       //if(d[u.second]!=u.first) continue;
       for(auto it:g[node]){
           if(d[it.first]>dist+it.second+1)  //since number of edges=nodes in between+1
           {
               d[it.first]=dist+it.second+1;
               pq.push({d[it.first], it.first});
           }
       }
  }
  //now we have minimum distances to reach each node, so check how many reachable with minMoves
  int ans = 0;
  for(int i = 0; i < n; ++i) { // add 1 for nodes that can be visited
      if(d[i] <= maxMoves) 
        ans++;   
   } 
  

  /*
  Now add for intermediate newly added nodes
  Eg. 0->1 and 10 in between

  Visitable from 0 -> maxMoves-(dist/moves already covered by 0 (from source)) 
  Visitable from 1 -> maxMoves-(dist/moves already covered by 1 (from source))
  
  To calculate Extra nodes I can visit we follow above
  */
  for(auto i : edges) {
      int src=i[0],dest=i[1], between=i[2];
      int x = max(0, (maxMoves - d[src])); // nodes visited using edge e[0]->e[1]
      int y = max(0, (maxMoves - d[dest])); // nodes visited using edge e[1]->e[0]
      ans += min(between, x + y); //minimum to avoid overlapping in counting
  }
  return ans;
