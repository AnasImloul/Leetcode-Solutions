class Solution {
    public int makeConnected(int n, int[][] connections) {
        int m = connections.length;
        if(m < n - 1) return -1;
        UnionFind uf = new UnionFind(n);
        
        for(int[] connection: connections){
            uf.union(connection[0], connection[1]);
        }
        return uf.getIsolated();
    }
}
class UnionFind{
    int[] root;
    int[] rank;
    int isolated;
    public UnionFind(int n){
        root = new int[n];
        rank = new int[n];
        for(int i = 0; i < n; i++){
            root[i] = i;
            rank[i] = 1;
        }
        isolated = 0;
    }
    public int find(int x){
        if(root[x] != x) root[x] = find(root[x]);
        return root[x];
    }
    public void union(int x, int y){
        int rootx = find(x);
        int rooty = find(y);
        if(rootx == rooty) return;
        if(rank[rootx] > rank[rooty]){
            root[rooty] = rootx;
        }else if(rank[rootx] < rank[rooty]){
            root[rootx] = rooty;
        }else{
            root[rootx] = rooty;
            rank[rooty] += 1;
        }
    }
    public int getIsolated(){
        for(int i = 0; i < root.length; i ++){
            if(root[i] == i) isolated++;
        }
        return isolated - 1;
    }
}
