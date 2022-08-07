class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        int n = numCourses;
        boolean [] visited = new boolean[n];
        boolean [] dfsVisited = new boolean[n];
        
        List<List<Integer>> adj = createAdjList(n,prerequisites);
        for(int i=0;i<n;i++){
            if(visited[i]==false){
                if(isCycle(i,adj,visited,dfsVisited)){
                    return false;
                }
            }
        }
        return true;
    }
    //find cycle in a directed graph
    private boolean isCycle(int s,List<List<Integer>> adj,boolean [] visited,boolean[] dfsVisited){
       
        visited[s]=true;
        dfsVisited[s]=true;
            
        for(int v:adj.get(s)){
            if(visited[v]==false){
              if(isCycle(v,adj,visited,dfsVisited)){
                return true;
                }  
            }else if(visited[v]==true && dfsVisited[v]==true) {
                return true;
            }   
        }
        dfsVisited[s]=false;
        return false;
    }
    
    private List<List<Integer>> createAdjList(int n,int[][] prerequisites){
        List<List<Integer>> adj = new ArrayList();
        
        for(int i=0;i<n;i++){
            adj.add(new ArrayList<>());
        }
        for(int[] e : prerequisites){
               adj.get(e[1]).add(e[0]);
        }
        return adj;
    }
}
