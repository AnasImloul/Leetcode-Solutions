// Runtime: 9 ms (Top 33.5%) | Memory: 41.11 MB (Top 16.7%)

class Solution {
    public String optimalDivision(int[] nums) {
    
         if(nums.length==1){
            return nums[0] + "";
        }else if(nums.length==2){
            StringBuilder sb=new StringBuilder();
            sb.append(nums[0] + "/" + nums[1]);
            return sb.toString();
        }
        
        StringBuilder sb=new StringBuilder();
         sb.append(nums[0]);
         sb.append("/(");
       for(int i=1;i<nums.length-1;i++){           
            sb.append(nums[i] + "/");
        }
        sb.append(nums[nums.length-1] + ")");
      
        return sb.toString();
    }
}