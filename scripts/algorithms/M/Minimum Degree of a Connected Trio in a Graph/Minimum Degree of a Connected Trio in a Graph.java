class Solution {
public int minTrioDegree(int n, int[][] edges) {
	// to store edge information
    boolean[][] graph = new boolean[n+1][n+1];
	//to store inDegrees to a node(NOTE: here inDegree and outDegree are same because it is Undirected graph)
    int[] inDegree = new int[n+1];
    
    for(int[] edge : edges) {
        graph[edge[0]][edge[1]] = true;
        graph[edge[1]][edge[0]] = true;
        
        inDegree[edge[0]]++;
        inDegree[edge[1]]++;
    }
    
    int result = Integer.MAX_VALUE;
    for(int i=1; i<=n; i++) {
        for(int j=i+1; j<=n; j++) {
            if(graph[i][j]) {
                for(int k=j+1; k<=n; k++) {
                    if(graph[i][k] && graph[j][k]) {
                        result = Math.min(result, inDegree[i] + inDegree[j] + inDegree[k] - 6);
                    }
                }
            }
        }
    }
    
    
    return result == Integer.MAX_VALUE ? -1 : result;
}
}