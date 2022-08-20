// Runtime: 193 ms (Top 55.29%) | Memory: 195.4 MB (Top 40.00%)

class Solution {
    public int networkBecomesIdle(int[][] edges, int[] patience) {
        int n = patience.length;

        // creating adjacency list
        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
        for(int i = 0 ; i < n ; i++ ) {
            adj.add(new ArrayList<>());
        }

        for(int[] edge : edges) {
            adj.get(edge[0]).add(edge[1]);
            adj.get(edge[1]).add(edge[0]);
        }

         // getting the distance array using dijkstra algorithm
        int[] dist = dijkstra(adj);

     // variable to store the result
        int ans = 0;

        // performing the calculations discussed above for each index
        for(int x = 1; x < n ; x++) {

            // round trip time
            int time = 2*dist[x];

            int p = patience[x];

            //total number of messages the station will send until it receives the reply of first message
            int numberOfMessagesSent = (time)/p;

            //handling an edge case if round trip time is a multiple of patience example time =24 patience = 4
            //then the reply would be received at 24 therefore station will not send any message at t = 24
            if(time%p == 0) {
                numberOfMessagesSent--;
            }

        // time of last message
            int lastMessage = numberOfMessagesSent*p;

            // updating the ans to store max of time at which the station becomes idle
            ans = Math.max(ans,lastMessage+ 2*dist[x]+1);

        }

        return ans;
    }

    // simple dijkstra algorithm implementation
    private int[] dijkstra(ArrayList<ArrayList<Integer>> adj) {

        int n = adj.size();

        int[] dist = new int[n];
        boolean[] visited = new boolean[n];

        Arrays.fill(dist,Integer.MAX_VALUE);
        dist[0] = 0;

        PriorityQueue<int[]> pq = new PriorityQueue<>((o1,o2)->o1[1]-o2[1]);

        pq.add(new int[]{0,0});

        while(!pq.isEmpty()) {
            int[] node = pq.remove();
            if(!visited[node[0]]) {
                visited[node[0]] = true;
                for(int nbr : adj.get(node[0])) {
                    if(dist[nbr] > dist[node[0]]+1) {
                        dist[nbr] = dist[node[0]]+1;
                        pq.add(new int[]{nbr,dist[nbr]});
                    }
                }
            }

        }

        return dist;
    }

}
