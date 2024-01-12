// Runtime: 0 ms (Top 100.0%) | Memory: 40.90 MB (Top 35.14%)

class Solution {
    int sum=0;
    public int subsetXORSum(int[] nums) {
        sum=0;
        return getAns(nums,0,0);
    }
    
    int getAns(int[] arr,int i,int cur){
        if(i==arr.length){
            return cur;
        }
        return getAns(arr,i+1,cur^arr[i]) + getAns(arr,i+1,cur);
    }
}
