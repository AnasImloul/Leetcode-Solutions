// Runtime: 13 ms (Top 29.67%) | Memory: 225.1 MB (Top 38.94%)
class Solution {
    public int[] rearrangeArray(int[] nums) {
        int[] res = new int[nums.length];
        int resIdx = 0;
        int posIdx = -1;
        int minusIdx = -1;

        for(int i=0;i<nums.length;i++){
            if(i % 2 == 0){
                posIdx++;
                while(nums[posIdx] <0 )posIdx++;
                res[resIdx++] = nums[posIdx];
            }
            else{
                minusIdx++;
                while(nums[minusIdx] > 0 )minusIdx++;
                res[resIdx++] = nums[minusIdx];
            }
        }

        return res;
    }
}