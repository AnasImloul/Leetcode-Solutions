// Runtime: 186 ms (Top 36.59%) | Memory: 87.4 MB (Top 48.79%)
class Solution {
    class pair implements Comparable<pair>{
        int pos;
        double time;
        pair(int pos,double time){
            this.pos=pos;
            this.time=time;
        }
        public int compareTo(pair o){
            return o.pos-this.pos;
        }
    }
    public int carFleet(int target, int[] position, int[] speed) {
        double []arr=new double[position.length];
        for(int i=0;i<position.length;i++){
            arr[i]=(target-position[i])*1.0/speed[i];
        }
        PriorityQueue<pair>pq=new PriorityQueue<>();
        for(int i=0;i<position.length;i++){
            pq.add(new pair(position[i],arr[i]));
        }
        double updatetime=0;
        int fleet=0;
        while(pq.size()>0){
            pair rem=pq.remove();
            if(updatetime<rem.time){
               fleet++;
               updatetime=rem.time;
            }
        }
        return fleet;
    }
}