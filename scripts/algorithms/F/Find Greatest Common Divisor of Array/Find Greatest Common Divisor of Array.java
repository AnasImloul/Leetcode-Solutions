// Runtime: 3 ms (Top 25.8%) | Memory: 42.56 MB (Top 95.7%)

class Solution {
    public int findGCD(int[] nums) {
        Arrays.sort(nums);
        int n=nums[nums.length-1];
        int result=nums[0];
        while(result>0){
            if(nums[0]%result==0 && n%result==0){
                break;
            }
            result--;
        }
        return result;
    }
}