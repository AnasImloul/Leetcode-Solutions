class Solution {
    int[] parent;
    int[] rank;
    
    public int regionsBySlashes(String[] grid) {
        parent = new int[4*grid.length*grid.length];
        rank = new int[4*grid.length*grid.length];
        
        for(int i=0;i<parent.length;i++){
            parent[i] = i;
            rank[i] = 0;
        }
        
        for(int i=0;i<grid.length;i++){
            for(int j=0;j<grid[i].length();j++){
                char ch = grid[i].charAt(j);
                
                int bno = i * grid.length + j;
                
                if(ch != '/'){
                    unionHelper(4*bno + 0 , 4*bno + 1);
                    unionHelper(4*bno + 2, 4*bno + 3);
                }
                
                if(ch != '\\'){
                    unionHelper(4*bno + 0 , 4*bno + 3);
                    unionHelper(4*bno + 1, 4*bno + 2);
                }
                
                if(i > 0){
                    int obno = (i-1) * grid.length + j;
                    unionHelper(4*bno + 0 , 4*obno + 2);
                }
                
                if(j > 0){
                    int obno = i * grid.length + (j-1);
                    unionHelper(4*bno + 3 , 4*obno + 1);
                }
                
            }
        }
        
        int count = 0;
        
        for(int i=0;i<parent.length;i++){
            if(parent[i] == i){
                count++;
            }
        }
        
        return count;       
        
    }
    
    
    public int find(int x){
        if(parent[x] == x){
            return parent[x];
        }else{
            parent[x] = find(parent[x]);
            return parent[x];
        }
    }
    public void union(int xl,int yl){
        if(rank[xl] < rank[yl]){
            parent[xl] = yl;
        }else if(rank[yl] < rank[xl]){
            parent[yl] = xl;
        }else{
            parent[xl] = yl;
            rank[yl]++;
        }
    }
    public void unionHelper(int x,int y){
        int xl = find(x);
        int yl = find(y);
        
        if(xl != yl){
            union(xl,yl);
        }
    }
}
