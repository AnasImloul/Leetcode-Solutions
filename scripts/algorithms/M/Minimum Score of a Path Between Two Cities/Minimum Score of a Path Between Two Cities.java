class Solution {
    class Pair{
        int f;
        int s;
        public Pair(int f,int s){
            this.f=f;
            this.s=s;
        }
    }
    int min;
    public int minScore(int n, int[][] roads) {
        min=Integer.MAX_VALUE;
       List<List<Pair>> l=new ArrayList<List<Pair>>();
        for(int i=0;i<n+1;i++){
            l.add(new ArrayList<Pair> ());
        }
       for(int i[]:roads){
           l.get(i[0]).add(new Pair(i[1],i[2]));
            l.get(i[1]).add(new Pair(i[0],i[2]));
       }
        boolean visited[]=new boolean[n+1];
        dfs(1,l,visited,n);
        return min;
    }
      
    
    public void dfs(int node,List<List<Pair>> l,boolean visited[],int n){
        
        visited[node]=true;
        for(Pair v:l.get(node)){
             min=Math.min(min,v.s);
            if(!visited[v.f]){
                visited[v.f]=true;
                dfs(v.f,l,visited,n);
            }
        }
    }
}