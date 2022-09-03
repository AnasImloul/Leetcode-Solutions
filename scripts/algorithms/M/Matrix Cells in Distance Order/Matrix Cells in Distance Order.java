// Runtime: 13 ms (Top 88.98%) | Memory: 44.4 MB (Top 93.55%)
//--------------------Method 1----------------------

class Solution {
    public int[][] allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {

        int [][]res=new int[rows*cols][2];

        int idx=0;

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                res[idx][0]=i;
                res[idx][1]=j;
                idx++;
            }
        }

        Arrays.sort(res,(a,b)->{
            int d1=Math.abs(a[0]-rCenter)+Math.abs(a[1]-cCenter);
            int d2=Math.abs(b[0]-rCenter)+Math.abs(b[1]-cCenter);

            return d1-d2;
        });

        return res;
    }
}

//--------------------Method 2--------------------

// class Solution {
// public int[][] allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {

// boolean [][]vis=new boolean[rows][cols];
// int [][]ans=new int[rows*cols][2];

// Queue<Pair> q=new LinkedList<>();
// q.add(new Pair(rCenter,cCenter));
// int idx=0;
// vis[rCenter][cCenter]=true;
// int [][]dir={{0,1},{1,0},{-1,0},{0,-1}};

// while(!q.isEmpty()){
// Pair curr=q.remove();
// ans[idx][0]=curr.r;
// ans[idx][1]=curr.c;
// idx++;

// for(int []d:dir){
// int nr=curr.r+d[0];
// int nc=curr.c+d[1];

// if(nr>=0 && nr<rows && nc>=0 && nc<cols && !vis[nr][nc]){
// vis[nr][nc]=true;
// q.add(new Pair(nr,nc));
// }
// }
// }

// return ans;
// }
// }

// class Pair{
// int r;
// int c;

// public Pair(int r, int c){
// this.r=r;
// this.c=c;
// }
// }