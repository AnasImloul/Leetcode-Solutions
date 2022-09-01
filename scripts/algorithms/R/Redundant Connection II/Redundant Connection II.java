// Runtime: 3 ms (Top 24.18%) | Memory: 44.9 MB (Top 16.79%)
class Solution {
    int[] dsu;
    public int[] findRedundantDirectedConnection(int[][] edges) {
        int n=edges.length;
        int[] parent=new int[n+1];
        Arrays.fill(parent,-1);

        int[] e2=null;
        int[] e1=null;
        boolean twopt=false;

        for(int[] edge: edges){

            int from=edge[0];
            int to=edge[1];

            if(parent[to]==-1){
                parent[to]=from;
            }else{
                twopt=true;
                e2=edge;
                e1=new int[]{parent[to],to};
                break;
            }
        }

        dsu=new int[edges.length+1];
        for(int i=0;i<=edges.length;i++){
            dsu[i]=i;
        }
        if(twopt==false){
            int[] res=null;

            for(int[] edge: edges){
                int from=edge[0];
                int to=edge[1];

                int fromlead=find(from);
                if(fromlead==to){
                    res=edge;
                    break;
                }else{
                    dsu[to]=fromlead;
                }
            }
            return res;
        }else{
            boolean iscycle=false;
            for(int[] edge: edges){
                if(edge==e2) continue;
                int from =edge[0];
                int to=edge[1];

                int fromlead=find(from);

                if(fromlead==to){
                    iscycle=true;
                    break;
                }else{
                    dsu[to]=fromlead;
                }
            }
            if(iscycle==true){
                return e1;
            }else{
                return e2;
            }
        }

    }
    public int find(int x){
        if(dsu[x]==x) return x;
        return dsu[x]=find(dsu[x]);
    }
}