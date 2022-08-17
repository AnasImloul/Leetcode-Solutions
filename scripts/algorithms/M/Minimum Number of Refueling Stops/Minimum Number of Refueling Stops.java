class Solution {
    public int minRefuelStops(int target, int startFuel, int[][] stations) {
        PriorityQueue<Integer> pq=new PriorityQueue<>((i1,i2)->i2-i1);
        int len=stations.length;
        int pre=0 ,cur, fuel=startFuel;
        int count=0;
        for(int i=0;i<=len;++i){
            cur=i==len?target:stations[i][0];
            fuel -= cur-pre;
            while(fuel<0 && !pq.isEmpty()){
                fuel += pq.poll();
                count++;
            }
            if(fuel<0) return -1;
            
            if(i!=len){
                pq.add(stations[i][1]);
                pre=cur;
            }
        }
        return count;
    }
}
