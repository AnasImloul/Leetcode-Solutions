class Solution {
    public int maxNumEdgesToRemove(int n, int[][] edges) 
    {
        Arrays.sort(edges , (a,b) -> b[0] - a[0]);
        
        int[] aparent = new int[n+1];
        int[] bparent = new int[n+1];
        
        int[] arank = new int[n+1];
        int[] brank = new int[n+1];
        
        for(int i=0;i<n+1;i++){
            aparent[i] = i;
            bparent[i] = i;
            arank[i] = 1;
            brank[i] = 1;
        }
        
        int amerged = 1;
        int bmerged = 1;
        int remove = 0;
        
        for(int[] edge : edges){
            if(edge[0] == 3){
                boolean aunion = union(edge[1] , edge[2] , aparent , arank);
                boolean bunion = union(edge[1] , edge[2] , bparent , brank);
                
                if(aunion == true)
                    amerged++;
                if(bunion == true)
                    bmerged++;
                if(aunion == false && bunion == false)
                    remove++;
            }
            else if(edge[0] == 1){
                boolean aunion = union(edge[1] , edge[2] , aparent , arank);
                if(aunion == true)
                    amerged++;
                else
                    remove++;
            }
            else{
                boolean bunion = union(edge[1] , edge[2] , bparent , brank);
                if(bunion == true)
                    bmerged++;
                else
                    remove++;
            }
            
        }
        if(amerged != n || bmerged != n)
                return -1;
            return remove;
    }
    
    public int find(int x , int[] parent){
        if(parent[x] == x)
            return x;
        int temp = find(parent[x] , parent);
        parent[x] = temp;
        return temp;
    }
    
    public boolean union(int x , int y , int[] parent , int[] rank){
        int lx = find(x , parent);
        int ly = find(y , parent);
        
        if(lx != ly){
            if(rank[lx] > rank[ly])
                parent[ly] = lx;
            else if(rank[ly] > rank[lx])
                parent[lx] = ly;
            else{
                parent[ly] = lx;
                rank[lx]++;
            }
            return true;
        }
        return false;
    }
}
