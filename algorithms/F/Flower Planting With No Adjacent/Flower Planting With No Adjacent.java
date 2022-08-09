class Solution {
    public int[] gardenNoAdj(int n, int[][] paths) {
        boolean[][] graph = new boolean[n][n];
        for(int i = 0;i<paths.length;i++){
            int u = paths[i][0]-1;
            int v = paths[i][1]-1;
            graph[u][v] = true;
            graph[v][u] = true;
        }
        int[] colored = new int[n];
        boolean[] available = new boolean[4];
        Arrays.fill(colored,-1);
        colored[0] = 1;
        for(int i = 1;i<n;i++){
            for(int j = 0;j<n;j++){
                if(graph[i][j] && colored[j]!=-1){
                    available[colored[j]-1]=true;
                }
            }
            int k,flag = 0;
            for(k = 0;k<4;k++){
                if(available[k]==false){
                    flag = 1;
                    break;
                }
            }
            colored[i] = k+1;
            Arrays.fill(available,false);
        }
        return colored;
    }
}
