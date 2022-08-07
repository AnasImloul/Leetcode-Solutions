class Solution {
//  BFS
// We add all 0 to the queue in the 0th level of the BFS. From there, every subsequent pair of indexes added would be 1 in the mat. THis way levels can represent the distance of a one from the closest 0 to it.
    boolean visited[][];
    
    // Could also convert the indexes to a single number by mat[0].length * i + j.
    class Pair{
        int x;
        int y;
        Pair(int x, int y){
            this.x = x;
            this.y = y;
        }
    }
    public int[][] updateMatrix(int[][] mat) {
        int level = 0;
        visited = new boolean[mat.length][mat[0].length];
        Queue<Pair> q = new ArrayDeque<>();
        // Addition of all pairs in mat that have 0.
        for(int i = 0; i < mat.length; i++){
            for(int j = 0; j < mat[0].length; j++){
                if(mat[i][j] == 0){
                    visited[i][j] = true;
                    q.add(new Pair(i, j));
                }
            }
        }
        while(q.size()>0){
            int size = q.size();
            while(size-- > 0){
                Pair p = q.remove();
                mat[p.x][p.y] = level;
                if(p.x > 0 && visited[p.x - 1][p.y] == false){
                    visited[p.x-1][p.y] = true;
                    q.add(new Pair(p.x-1, p.y));
                }
                if(p.x < mat.length - 1 && visited[p.x + 1][p.y] == false){
                    visited[p.x+1][p.y] = true;
                    q.add(new Pair(p.x+1, p.y));
                    
                }
                if(p.y > 0 && visited[p.x][p.y-1] == false){
                    visited[p.x][p.y-1] = true;
                    q.add(new Pair(p.x, p.y-1));
                    
                }
                if(p.y < mat[0].length-1 && visited[p.x][p.y + 1] == false){
                    visited[p.x][p.y+1] = true;
                    q.add(new Pair(p.x, p.y + 1));
                }
            }
            level++;
        }
        return mat;
    }
}
