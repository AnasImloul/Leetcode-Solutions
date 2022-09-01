// Runtime: 429 ms (Top 10.68%) | Memory: 270.9 MB (Top 16.79%)
class Solution {
    public int reachableNodes(int[][] edges, int maxMoves, int n) {
        int[][] graph = new int[n][n];
        for ( int[] t: graph ) {
            Arrays.fill(t, -1);
        }
        for ( int[] t: edges ) {
            graph[t[0]][t[1]] = t[2];
            graph[t[1]][t[0]] = t[2];
        }
        PriorityQueue<int[]> heap = new PriorityQueue<>( (a, b) -> b[1]-a[1] );
        int ans = 0;
        boolean[] vis = new boolean[n];
        heap.offer(new int[]{0, maxMoves});
        while ( !heap.isEmpty() ) {
            int[] info = heap.poll();
            int nearestNodeId = info[0];
            int maxMovesRemaining = info[1];
            if ( vis[nearestNodeId] ) {
                continue;
            }
            // visiting the current node
            vis[nearestNodeId] = true;
            // since we visited this node we increment our counter
            ans++;
            for ( int i=0; i<n; i++ ) {
                // checking if we do have an edge
                if ( graph[nearestNodeId][i]!=-1 ) {
                    if ( !vis[i] && maxMovesRemaining>=graph[nearestNodeId][i]+1 ) {
                        heap.offer( new int[] {i, maxMovesRemaining-graph[nearestNodeId][i]-1} );
                    }
                    int movesTaken = Math.min(maxMovesRemaining, graph[nearestNodeId][i]);
                    graph[nearestNodeId][i] -= movesTaken;
                    graph[i][nearestNodeId] -= movesTaken;
                    ans += movesTaken;
                }
            }
        }
        return ans;
    }
}