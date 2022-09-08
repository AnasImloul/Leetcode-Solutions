// Runtime: 58 ms (Top 49.87%) | Memory: 123 MB (Top 65.81%)
class Solution {
    public int minimumTime(int n, int[][] relations, int[] time) {
        List<Integer> adj[] = new ArrayList[n];
        int indegree[] = new int[n];
        int completionTime[] = new int[n];
        for(int i=0; i<n; i++) adj[i] = new ArrayList<>();
        for(int relation[]: relations){
            int u = relation[0]-1, v = relation[1]-1;
            adj[u].add(v);
            indegree[v]++;
        }
        Queue<Integer> q = new LinkedList<>();
        for(int i=0; i<n; i++){
            if(indegree[i] == 0){ // if no prerequisite add it to queue
                completionTime[i] = time[i];
                q.add(i);
            }
        }

        while(!q.isEmpty()){
            int u = q.poll();
            for(int v: adj[u]){
                completionTime[v] = Math.max(completionTime[v], completionTime[u] + time[v]);
                if(--indegree[v] == 0){ // when all prerequisite are complete add the next course
                    q.add(v);
                }
            }
        }
        int res=0;
        for(int x: completionTime) res = Math.max(res, x);
        return res;
    }
}
