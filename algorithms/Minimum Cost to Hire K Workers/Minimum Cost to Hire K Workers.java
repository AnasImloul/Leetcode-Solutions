class node implements Comparable<node>{
    int q;
    int w;
    double wpq;
    node(int qual, int wage){
        q = qual;
        w = wage;
        wpq = (double)w/q;
    }
    
    public int compareTo(node o){
        return Double.compare(this.wpq, o.wpq);
    }
}
class Solution {
    
    public double mincostToHireWorkers(int[] quality, int[] wage, int k) {
        
        ArrayList<node> arr = new ArrayList<>();
        //main constant value of importance is wage/quality
        for(int i = 0; i< wage.length; i++) {
            arr.add(new node(quality[i], wage[i]));
        }
        
        Collections.sort(arr);
        double res = Double.MAX_VALUE;
        PriorityQueue<Integer> maxheap = new PriorityQueue<>(Collections.reverseOrder());
        int sum = 0;
        for(node n: arr) {
            
            maxheap.add(n.q);
            sum = sum+n.q;
            
            if(maxheap.size()>k){
                sum -= maxheap.poll();
            }
            
            if(maxheap.size() == k) {
                res = Math.min(res,sum*n.wpq);
            }
        }
        
        return res;
        
    }
}
