class Solution {
    public boolean canReorderDoubled(int[] arr) {
        Map<Integer,Integer> map=new HashMap<>();
        int zeroCount=0,out=0,len=arr.length;
        Arrays.sort(arr);
        for(int ar:arr){
           if(ar%2==1)
               map.put(ar,map.getOrDefault(ar,0)+1);
           else
           {
               if(ar>0)
               {
                   int val=map.getOrDefault(ar/2,0);
                   if(val>0){
                       out++;
                       map.put(ar/2,val-1);
                   }
                   else map.put(ar,map.getOrDefault(ar,0)+1);
               }
               else if(ar<0)
               {
                  int val=map.getOrDefault(ar2,0);
                   if(val>0){
                       out++;
                       map.put(ar2,val-1);
                   } 
                   else map.put(ar,map.getOrDefault(ar,0)+1);
               }
               else zeroCount++;   
           }
        }
        zeroCount=zeroCount/2;
        return out+zeroCount==len/2;
    }
}
