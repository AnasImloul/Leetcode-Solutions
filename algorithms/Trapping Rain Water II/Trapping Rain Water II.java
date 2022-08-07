class Solution {
    public class pair implements Comparable<pair>{
        int row;
        int col;
        int val;
        pair(int row, int col,int val){
            this.row = row;
            this.col = col;
            this.val = val;
        }
        public int compareTo(pair o){
            return this.val - o.val;
        }
    }
    int[][] dir = {{1,0},{0,-1},{-1,0},{0,1}};
    public int trapRainWater(int[][] heightMap) {
        int n = heightMap.length;
        int m = heightMap[0].length;
        
        PriorityQueue<pair> pq = new PriorityQueue<>();
        
        boolean[][] visited = new boolean[n][m];
        
        // add all the boundary elements in pq
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == 0 || j == 0 || i == n-1 || j == m-1){
                    pq.add(new pair(i, j, heightMap[i][j]));
                    visited[i][j] = true;
                }
            }
        }
        
        int ans = 0;
        
        while(pq.size() > 0){
            pair rem = pq.remove();
            for(int i = 0; i < 4; i++){
                
                int rowdash = rem.row + dir[i][0];
                int coldash = rem.col + dir[i][1];
                
                if(rowdash >= 0 && coldash >= 0 && rowdash < n && coldash < m && visited[rowdash][coldash] == false){
                    visited[rowdash][coldash] = true;
                    if(heightMap[rowdash][coldash] >= rem.val){
                        pq.add(new pair(rowdash, coldash, heightMap[rowdash][coldash])); // boundary is updated
                    }else{
                        int waterstored = rem.val - heightMap[rowdash][coldash];
                        ans += waterstored;                                             // now this will act as a wall add in pq
                        pq.add(new pair(rowdash, coldash, heightMap[rowdash][coldash] + waterstored));
                    }
                }
            }
        }
        return ans;
    }
}
