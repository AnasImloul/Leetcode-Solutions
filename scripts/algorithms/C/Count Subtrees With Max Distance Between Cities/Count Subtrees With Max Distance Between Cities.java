// Runtime: 232 ms (Top 14.5%) | Memory: 44.30 MB (Top 38.1%)

class Solution {
    public int[] countSubgraphsForEachDiameter(int n, int[][] edges) {
         
        
       ArrayList<Integer>[] graph = (ArrayList<Integer>[]) new ArrayList[n];
       for (int i = 0; i < n; i++) graph[i] = new ArrayList<>();
        
         for(int i=0;i<edges.length;i++)
         {
             int u = edges[i][0];
             int v = edges[i][1];
             
             --u;
             --v;
             
             graph[u].add(v);
             graph[v].add(u);
         }
        
         int[] darr = new int[n-1];
        
         for(int mask=0;mask<(1<<(n));mask++)
         {
             int d = getmax(mask , graph);
             
             if(d>0)
             {
                 darr[d-1]++;
             }
         }
        
        return darr;
         
    }
    
   int getmax(int mask , ArrayList<Integer>[] graph)
    {
          
          int maxd = -1;
        
          for(int i=0;i<15;i++)
          {      
              if( (mask & (1<<i)) !=0)
              {
                  maxd = Math.max(maxd , dfs(i , graph , mask));
              }
          }
        
        return maxd;
    }
    
    int dfs(int node , ArrayList<Integer>[] graph , int mask)
    {
        
        
      Queue<Integer> q
            = new LinkedList<>();
        q.add(node);
        int dist = -1;
        int curr = mask;
        
        while(!q.isEmpty())
        {
           dist++;
        
         for(int l=q.size()-1;l>=0;l--) {   
            int z1 = q.peek();
            curr = curr ^ (1<<z1);
            q.remove();
            
            for(int z : graph[z1])
            {
               if(((mask & (1<<z))!=0) && ((curr & (1<<z))!=0))
               {  
                  q.add(z); }
            }
         }
                  
        }
        
        if(curr!=0)
        {
            return -1;
        }
        
        return dist;
       
    }
}