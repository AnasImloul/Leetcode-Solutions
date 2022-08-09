class Solution {
    int[] rank;
    int[] parent;
    int[] rival;
    public boolean possibleBipartition(int n, int[][] dislikes) {
        rank = new int[n+1];
        rival = new int[n+1];
        parent = new int[n+1];
        for(int i = 1;i <= n;i++){
            rank[i] = 1;
            parent[i] = i;
        }
        for(int[] dis : dislikes){
            int x = dis[0], y = dis[1];
            if(find(x) == find(y))
                return false;
            if(rival[x] != 0)
                union(rival[x], y);
            else
                rival[x] = y;
            if(rival[y] != 0)
                union(rival[y], x);
            else
                rival[y] = x;
        }
        return true;
    }
    public int find(int x){
        if(parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }
    public void union(int x, int y){
        int x_set = find(x);
        int y_set = find(y);
        if(x_set == y_set)
            return;
        if(rank[x_set] < rank[y_set])
            parent[x_set] = y_set;
        else if(rank[y_set] < rank[x_set])
            parent[y_set] = x_set;
        else{
            parent[x_set] = y_set;
            rank[y_set]++;
        }
    }
}
