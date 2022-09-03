// Runtime: 5 ms (Top 93.32%) | Memory: 48.7 MB (Top 36.20%)
class Solution {
    // g1-> graph with red edges
    // g2-> graph with blue edges
    List<Integer> g1[], g2[];
    int[] dist1, dist2, ans;
    int MX = (int) 2e9;

    public int[] shortestAlternatingPaths(int n, int[][] redEdges, int[][] blueEdges) {
        dist1 = new int[n];
        dist2 = new int[n];
        g1=new ArrayList[n];
        g2=new ArrayList[n];
        ans=new int[n];
        for (int i=0;i<n;i++){
            g1[i]=new ArrayList<>();
            g2[i]=new ArrayList<>();
            dist1[i]=MX;
            dist2[i]=MX;
            ans[i]=MX;
        }
        for (int i=0;i<redEdges.length;i++){
            int u=redEdges[i][0];
            int v=redEdges[i][1];
            g1[u].add(v);
        }
        for (int i=0;i<blueEdges.length;i++){
            int u=blueEdges[i][0];
            int v=blueEdges[i][1];
            g2[u].add(v);
        }
        dist1[0]=0;
        dist2[0]=0;
        dfs(0,true);
        dfs(0,false);
        for (int i=0;i<n;i++){
            ans[i]=Math.min(dist1[i], dist2[i]);
            if (ans[i]==MX) ans[i]=-1;
        }
        return ans;
    }
    public void dfs(int u, boolean flag) {
        if (flag) {
            for (int v: g1[u]) {
                if (dist1[v]>dist2[u]+1){
                    dist1[v]=dist2[u]+1;
                    dfs(v,!flag);
                }
            }
        } else {
            for (int v: g2[u]) {
                if (dist2[v]>dist1[u]+1){
                    dist2[v]=dist1[u]+1;
                    dfs(v,!flag);
                }
            }
        }
    }
}