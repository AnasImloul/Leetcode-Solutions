// Runtime: 27 ms (Top 42.47%) | Memory: 65.2 MB (Top 60.25%)
class Solution {
        ArrayList<ArrayList<Integer>> adj =new ArrayList<>();
        int res[];
    public int[] loudAndRich(int[][] richer, int[] quiet) {
        int n=quiet.length;
        res=new int[n];
        Arrays.fill(res,-1);
         for(int i=0;i<n;i++)
            adj.add(new ArrayList<Integer>());
        for(int i=0;i<richer.length;i++)
        {
            if(adj.get(richer[i][1])==null)
                adj.add(new ArrayList<>());
            adj.get(richer[i][1]).add(richer[i][0]);
        }
        for(int i=0;i<n;i++)
            dfs(i,quiet);
        return res;
    }
    public int dfs(int node ,int[] quiet)
    {
        if(res[node]==-1)
        {
            res[node]=node;
            for(int v:adj.get(node)){
                int cand=dfs(v,quiet);
                if(quiet[cand]<quiet[res[node]])
                res[node]=cand;
            }
        }
        return res[node];
    }
}