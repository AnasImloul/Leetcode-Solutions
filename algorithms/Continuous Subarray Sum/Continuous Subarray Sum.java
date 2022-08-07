class Solution {
    public boolean checkSubarraySum(int[] nums, int k) {
        boolean t[]=new boolean[nums.length+1];
        Arrays.fill(t,false);
       return help(nums.length,nums,k,0,0,t);
    }
    public boolean help(int i,int nums[],int k,int sum,int size,boolean t[]){
        if(size>=2&&sum%k==0){
            return true;
        }
        if(i==0){
            return false;
        }
        if(t[i-1]!=false){
            return t[i-1];
        }
        if(size>0){
         return t[i]=help(i-1,nums,k,sum+nums[i-1],size+1,t);
        }
        return t[i]=help(i-1,nums,k,sum+nums[i-1],size+1,t)||help(i-1,nums,k,sum,size,t);
    }
}
---------------------------------------------------------------------------------------------
class Solution {
    public boolean checkSubarraySum(int[] nums, int k) {
      int sum=0;
      HashMap<Integer,Integer>h=new HashMap<>();
      h.put(0,-1);
      for(int i=0;i<nums.length;i++){
          sum+=nums[i];
          sum=k==0?sum:sum%k;
          if(h.containsKey(sum)&& i-h.get(sum)>=2){
              return true;
          }
          h.put(sum,h.getOrDefault(sum,i));
      }  
        return false;
    }
}
