class Solution {
    class Pair{
        int node;
        int dist;
        Pair(int node , int dist){
            this.node = node;
            this.dist = dist;
        }
    }
    public int countPaths(int n, int[][] roads) {
        int mod = (int)Math.pow(10 , 9) + 7;
        ArrayList<ArrayList<Pair>> adj = new ArrayList<>();
        int rows = roads.length;
        for(int i = 0 ; i < n ; i++)
            adj.add(new ArrayList<Pair>());
        for(int i = 0 ; i < rows ; i++){
            int from = roads[i][0];
            int to = roads[i][1];
            int dis = roads[i][2];
            adj.get(from).add(new Pair(to , dis));
            adj.get(to).add(new Pair(from , dis));
        }
        PriorityQueue<Pair> pq = new PriorityQueue<>((aa , bb) -> aa.dist - bb.dist);
        pq.add(new Pair(0 , 0));
        long[] ways = new long[n];
        ways[0] = 1;
        int[] dist = new int[n];
        Arrays.fill(dist , Integer.MAX_VALUE);
        dist[0] = 0;
        while(!pq.isEmpty()){
            Pair p = pq.remove();
            int node = p.node;
            int dis = p.dist;
            for(Pair pa : adj.get(node)){
                if((dis + pa.dist) < dist[pa.node]){
                    ways[pa.node] = ways[node];
                    dist[pa.node] = dis + pa.dist;
                    pq.add(new Pair(pa.node , dist[pa.node]));
                }
                else if((dis + pa.dist) == dist[pa.node]){
                    ways[pa.node] += ways[node];
                    ways[pa.node] = ways[pa.node] % mod;
                }
            }
        }
        return (int)ways[n - 1];
    }
}
