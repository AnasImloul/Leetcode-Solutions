class Solution {
    public int minFlips(int[][] mat) {
        int m = mat.length, n = mat[0].length;
        Set<Integer> visited = new HashSet<>();
        Queue<Integer> queue = new LinkedList<>();
        int steps = 0;
        
        int initialState = toBinary(mat);
        queue.add(initialState);
        visited.add(initialState);
        
        while (!queue.isEmpty()) {
            int size = queue.size();
            
            for (int i = 0; i < size; i++) {
                int state = queue.poll();
                if (state == 0) return steps;
                int mask = 1;

                for (int y = 0; y < m; y++) {
                    for (int x = 0; x < n; x++) {
                        int nextState = flip(state, x, y, n, m);
                        if (!visited.contains(nextState)) {
                            visited.add(nextState);
                            queue.add(nextState);
                        }
                        mask = mask << 1;
                    }
                }
            }
            steps++;
        }
        return -1;
    }
    
    private int toBinary(int[][] M) {
        int bin = 0;
        for (int y = 0; y < M.length; y++) {
            for (int x = 0; x < M[0].length; x++) {
                bin = (bin << 1) + M[y][x];
            }
        }
        return bin;
    }
    
    private int flip(int state, int x, int y, int n, int m) {
        int flip = 1 << ((y*n) + x);
        flip += (x > 0) ? 1 << ((y*n) + (x-1)) : 0;
        flip += (x < n-1) ? 1 << ((y*n) + (x+1)) : 0;
        flip += (y > 0) ? 1 << (((y-1)*n) + x) : 0;
        flip += (y < m-1) ? 1 << (((y+1)*n) + x) : 0;
        return state ^ flip;
    }
}
