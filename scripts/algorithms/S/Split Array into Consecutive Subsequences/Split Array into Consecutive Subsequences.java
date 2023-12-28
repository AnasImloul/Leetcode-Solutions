// Runtime: 50 ms (Top 12.39%) | Memory: 45.60 MB (Top 38.5%)

class Solution {
    public boolean isPossible(int[] nums) {
        Map<Integer,Integer> possibility = new HashMap<>();
        Map<Integer,Integer> counts = new HashMap<>();
        for(int num:nums){
            counts.put(num,counts.getOrDefault(num,0)+1);
        }
        for(int num:nums){
            if(counts.get(num)==0)continue;
            if(possibility.getOrDefault(num,0)>0){
                possibility.put(num,possibility.getOrDefault(num,0)-1);
                possibility.put(num+1,possibility.getOrDefault(num+1,0)+1);
            }
            else if( counts.getOrDefault(num+1,0)>0 && counts.getOrDefault(num+2,0)>0 ){
                possibility.put(num+3,possibility.getOrDefault(num+3,0)+1);
                counts.put(num+1,counts.getOrDefault(num+1,0)-1);
                counts.put(num+2,counts.getOrDefault(num+2,0)-1);
            }
            else{
                return false;
            }
            counts.put(num,counts.get(num)-1);
        }
        return true;
    }
}
