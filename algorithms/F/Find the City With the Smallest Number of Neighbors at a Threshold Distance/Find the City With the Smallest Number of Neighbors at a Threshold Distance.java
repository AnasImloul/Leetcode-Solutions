class Solution {
    public int findTheCity(int n, int[][] edges, int distanceThreshold) {
        int[][] graph = new int[n][n];
        for(int[] row: graph)
            Arrays.fill(row, Integer.MAX_VALUE);
        
        for(int i = 0; i < n; i++)
            graph[i][i] = 0;
        
        for(int[] edge: edges)
        {
            graph[edge[0]][edge[1]] = edge[2];
            graph[edge[1]][edge[0]] = edge[2];
        }
        
        for(int k = 0; k < n; k++)
        {
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    if(graph[i][k] != Integer.MAX_VALUE && graph[k][j] != Integer.MAX_VALUE)
                    {
                        if(graph[i][k] + graph[k][j] < graph[i][j])
                            graph[i][j] = graph[i][k] + graph[k][j];
                    }
                }
            }
        }
        
        int ans = 0;
        int city = Integer.MAX_VALUE;;
        
        for(int i = 0; i < n; i++)
        {
            int current = 0;
            for(int j = 0; j < n; j++)
            {
                if(i != j && graph[i][j] <= distanceThreshold)
                    current++;
            }
            if(current <= city)
            {
                ans = i;
                city = current;
            }
        }
        
        return ans;
    }
}
