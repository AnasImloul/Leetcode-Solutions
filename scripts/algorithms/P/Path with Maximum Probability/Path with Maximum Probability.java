// Runtime: 82 ms (Top 52.25%) | Memory: 75.8 MB (Top 66.61%)
class Pair{
    int to;
    double prob;
    public Pair(int to,double prob){
        this.to=to;
        this.prob=prob;
    }
}
class Solution {
    public double maxProbability(int n, int[][] edges, double[] succProb, int start, int end) {
        List<List<Pair>> adj=new ArrayList<>();
        for(int i=0;i<n;i++){
            adj.add(new ArrayList<Pair>());
        }
        for(int i=0;i<edges.length;i++){
            adj.get(edges[i][0]).add(new Pair(edges[i][1],succProb[i]));
            adj.get(edges[i][1]).add(new Pair(edges[i][0],succProb[i]));
        }
        //node,to node,probability
        double probs[]=new double[n];
        Arrays.fill(probs,0.0);
        probs[start]=1.0;
        PriorityQueue<Pair> pq=new PriorityQueue<>((p1,p2)->Double.compare(p2.prob,p1.prob));
        pq.offer(new Pair(start,1.0));
        while(!pq.isEmpty()){
            Pair curr=pq.poll();
            for(Pair x:adj.get(curr.to)){
                if(((curr.prob)*(x.prob))>probs[x.to]){
                    probs[x.to]=((curr.prob)*(x.prob));
                    pq.offer(new Pair(x.to,probs[x.to]));

                }
                else{
                    continue;
                }
            }
        }
        return probs[end];
    }
}