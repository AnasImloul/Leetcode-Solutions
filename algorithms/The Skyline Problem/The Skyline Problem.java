class height implements Comparable<height>{
    int val = -1;
    int pos = -1;
    boolean isStart = false;
    height(int a, int b, boolean c){
        val = a;
        pos = b;
        isStart = c;
    }
    public int compareTo(height h){
        if(this.pos != h.pos)
            return this.pos-h.pos;
        if(isStart)
            return -1;
        if(h.isStart)
            return 1;
        
        return this.val-h.val;
    }
}
class Solution {
    public List<List<Integer>> getSkyline(int[][] buildings) {
        
        PriorityQueue<height> mQ = new PriorityQueue<>();
        int len = buildings.length;
        for(int[] b: buildings) {
            mQ.add(new height(b[2],b[0],true));
            mQ.add(new height(b[2],b[1],false));
        }
        PriorityQueue<Integer> heap = new PriorityQueue<>(Collections.reverseOrder());
        heap.add(0);
        int prevHeight = 0;
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> lst;
        while(mQ.size()>0) {
            height h = mQ.poll();
            if(h.isStart){
                heap.offer(h.val);
            } else {
                heap.remove(h.val);
            }
            
            if(prevHeight != heap.peek()){
                lst = new ArrayList<>();
                lst.add(h.pos);
                
                if(res.size() > 0 && res.get(res.size()-1).get(0) == h.pos){
                    lst.add(Math.max(heap.peek(), res.get(res.size()-1).get(1)));
                    res.remove(res.size()-1);
                } else 
                    lst.add(heap.peek());
                res.add(lst);
                prevHeight = heap.peek();
            }
        }
        return res;
    }
}
