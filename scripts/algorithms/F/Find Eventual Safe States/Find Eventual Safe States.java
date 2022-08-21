// Runtime: 7 ms (Top 80.80%) | Memory: 65.9 MB (Top 65.16%)

class Solution {
   public List<Integer> eventualSafeNodes(int[][] graph) {
    int n=graph.length;
    List<Integer> ans=new ArrayList<>();

    boolean visited[]=new boolean[n];
    boolean dfsVisited[]=new boolean[n];

    boolean nodeCycles[]=new boolean[n];

    for(int i=0;i<n;i++){
        if(visited[i]==false){
             isCycle(i,graph,dfsVisited,visited,nodeCycles);
        }
    }
    for(int i=0;i<nodeCycles.length;i++){
        if(nodeCycles[i]==false)
            ans.add(i);
    }
    return ans;
}

public boolean isCycle(int node,int graph[][],boolean dfsVisited[],boolean visited[],boolean [] nodeCycles) {
    visited[node]=true;
    dfsVisited[node]=true;

    for(int adjNode:graph[node]){
        if(visited[adjNode]==false){
           if(isCycle(adjNode,graph,dfsVisited,visited,nodeCycles))
                return nodeCycles[node]=true;
        }else if(visited[adjNode]==true && dfsVisited[adjNode]==true){
            return nodeCycles[node]=true;
        }
    }
    dfsVisited[node]=false;
    return false;
}
}