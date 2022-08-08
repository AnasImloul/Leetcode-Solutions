class Solution {
    public int minTime(int n, int[][] edges, List<Boolean> hasApple) {
        HashMap<Integer,List<Integer>> graph = new HashMap<>(n);
        for(int edge[] : edges){
            int a = edge[0], b = edge[1];
            graph.putIfAbsent(a, new LinkedList<>());
            graph.putIfAbsent(b, new LinkedList<>());
            graph.get(a).add(b);
            graph.get(b).add(a);
        }
        
        boolean[] visited = new boolean[n];
        Arrays.fill(visited,false);
        
        int a = move(0,graph,hasApple,n,visited);
        
        return a==-1?0:a;
    }
                
    public int move(int i,HashMap<Integer,List<Integer>> graph,List<Boolean> hasApple,int n,boolean[] visited){
        visited[i]=true;
        boolean cont = false;
        if(hasApple.get(i)){
            cont=true;
        }
        
        List<Integer> list = graph.get(i);
        
        if(list==null){
            return cont?0:-1;
        }
        int j = 0;
        for(int k : list){
            if(!visited[k]){
                int a = move(k,graph,hasApple,n,visited);
                if(a!=-1){
                    j+=2+a;
                }
            }
        }
        if(j==0 && cont) return 0;
        return j==0?-1:j;
    }
}