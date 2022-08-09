class Solution {
    public int getMaximumConsecutive(int[] coins) {
      if(coins.length==0 && coins==null)
          return 0;
      TreeMap<Integer,Integer> map=new TreeMap<Integer,Integer>();
      for(int i:coins)
          map.put(i,map.getOrDefault(i,0)+1);
      int range=0;
      for(int i:map.keySet()){
       if(range==0 && i==1)
       range=i*map.get(i);
       else if(range!=0 && range+1>=i)
         range+=i*map.get(i);
       else 
        break;
      }
     return range+1;
    }
}
