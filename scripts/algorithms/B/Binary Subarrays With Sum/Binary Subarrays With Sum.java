class Solution {
public int numSubarraysWithSum(int[] nums, int goal) {
    
    int pre=0,cnt=0;
    HashMap<Integer,Integer> m=new HashMap();
    for(int i:nums){
        
        pre+=i;
     //   if(pre-goal<0)continue;
        if(pre-goal==0)cnt++;
        
        if(m.containsKey(pre-goal)){
            cnt+=m.get(pre-goal);
            
            
        }
        m.put(pre,m.getOrDefault(pre,0)+1);

        
        
    }
    
    return cnt;
}
