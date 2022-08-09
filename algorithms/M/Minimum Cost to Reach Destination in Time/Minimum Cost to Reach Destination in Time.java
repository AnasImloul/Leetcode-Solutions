Dijkstra's Algo : 34 ms

class Solution {
    public int minCost(int maxTime, int[][] edges, int[] costVtx) {
        int N = costVtx.length;
        ArrayList<int[]>[] graph = new ArrayList[N];
        for(int i = 0; i < N ; i++) graph[i] = new ArrayList<>();
        
        for(int[] e : edges){
            int u = e[0], v = e[1], w = e[2];
            graph[u].add(new int[]{v, w});
            graph[v].add(new int[]{u, w});
        }
        int[] timeHold = new int[N];
        Arrays.fill(timeHold, (int) 1e9);
        PriorityQueue<int[]> pq = new PriorityQueue<>((a,b) -> {
            return a[1] - b[1];
        });
        // vtx | cost | time 
        pq.add(new int[]{0, costVtx[0], 0});
        timeHold[0] = 0;
        while(!pq.isEmpty()){
            int[] p = pq.remove();
            int vtx = p[0], cost = p[1], time = p[2]; 
            if(vtx == costVtx.length - 1) return cost;
            for(int[] e : graph[vtx]){
                int v = e[0], n_time = e[1];
                if(time + n_time > maxTime) continue;
                if(time + n_time < timeHold[v]){
                    timeHold[v] = n_time + time;
                    pq.add(new int[]{v, cost + costVtx[v], timeHold[v]});
                }
            }
        }
        return -1;
    }
}

Memoization : 234 ms

class Solution {
    ArrayList<int[]>[] graph;
    int[][] dp;
    public int minCost(int maxTime, int[][] edges, int[] passingFees) {
        int n = 1000;
        dp = new int[1001][maxTime + 1];
        for(int[] d : dp) Arrays.fill(d, -1);
        graph = new ArrayList[n];
        for(int i = 0; i < n ; i++){
            graph[i] = new ArrayList<>();
        }
        for(int[] e : edges){
            int u = e[0], v = e[1], w = e[2];
            graph[u].add(new int[]{v,w});
            graph[v].add(new int[]{u,w});
        }
        int ans = costMaker(maxTime, passingFees, 0);
        return ans >= (int) 1e8 ? -1 : ans;
    }
    
    public int costMaker(int time, int[] fees, int src){
        if(time < 0) return (int) 1e8;
        if(src == fees.length - 1) return dp[src][time] =  fees[src];
        if(dp[src][time] != -1) return dp[src][time];
        int cost = (int) 1e8;
        for(int[] e : graph[src]){
            int v = e[0], w = e[1];
            cost = Math.min(cost, costMaker(time - w, fees, v));
        }
        return dp[src][time] = cost + fees[src];
    }
}


