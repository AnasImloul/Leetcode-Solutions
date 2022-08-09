class Solution {
    public int[] avoidFlood(int[] rains) {
        HashMap<Integer,Integer> map = new HashMap<>();
        TreeSet<Integer> drydays = new TreeSet<>();
        int ans [] = new int [rains.length];
        for(int i =0;i<rains.length;i++){
            
            if(rains[i]==0){
                drydays.add(i);
             ans[i]=1;
            }
            else{
                if(map.containsKey(rains[i])){
                    Integer rainy_day = map.get(rains[i]);
                    Integer avail_day = drydays.higher(rainy_day);
                    if(avail_day==null){
                        return new int [0];
                    }else{
                        ans[avail_day]=rains[i];
                        map.put(rains[i],i);
                        drydays.remove(avail_day);
                    ans[i]=-1;
                    }
                    
                }
                else{
                    map.put(rains[i],i);
                 ans[i]=-1;
                }
            }
            
        }
        return ans ;
    }
}
