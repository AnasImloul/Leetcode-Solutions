// Runtime: 324 ms (Top 10.95%) | Memory: 130.5 MB (Top 57.67%)
class Solution {
    int dp[];
    //We use memoization
    public int countRestrictedPaths(int n, int[][] edges) {
        int[] dist = new int[n+1];
        dp = new int[n+1];
        Arrays.fill(dp,-1);
        Map<Integer, Map<Integer, Integer>> graph = new HashMap<>();
        //Create the graph from input edges
        for(int[] e : edges){
            graph.putIfAbsent(e[0], new HashMap<>());
            graph.putIfAbsent(e[1], new HashMap<>());
            graph.get(e[0]).put(e[1],e[2]);
            graph.get(e[1]).put(e[0],e[2]);
        }
        //Single source shortest distance - something like Dijkstra's
        PriorityQueue<int[]> pq = new PriorityQueue<>((a,b)->(a[1]-b[1]));
        int[] base = new int[2];
        base[0]=n;
        pq.offer(base);
        while(!pq.isEmpty()){
            int[] currNode = pq.poll();

            for(Map.Entry<Integer, Integer> neighbour: graph.get(currNode[0]).entrySet()){
                int node = neighbour.getKey();
                int d = neighbour.getValue()+currNode[1];
                if(node==n) continue;
                //Select only those neighbours, whose new distance is less than existing distance
                //New distance = distance of currNode from n + weight of edge between currNode and neighbour

                if( dist[node]==0 || d < dist[node]){
                    int[] newNode = new int[2];
                    newNode[0]=node;
                    newNode[1]=d;
                    pq.offer(newNode);
                    dist[node]= d;
                }
            }
        }

        return find(1,graph,n,dist);
    }
    //This method traverses all the paths from source node to n though it's neigbours
    private int find(int node, Map<Integer, Map<Integer, Integer>> graph, int n, int[] dist ){
        if(node==n){
            return 1;
        }

        //Memoization avoid computaion of common subproblems.
        if(dp[node]!=-1) return dp[node];

        int ans = 0;
        for(Map.Entry<Integer, Integer> neighbour: graph.get(node).entrySet()){
                int currNode = neighbour.getKey();
                int d = dist[currNode];
                if( dist[node] > d){
                    ans = (ans + find(currNode, graph, n, dist)) % 1000000007;
            }
        }

        return dp[node] = ans;
    }
}