class Solution {
    public int minimumDeletions(int[] nums) {
        int max = Integer.MIN_VALUE;
        int min = Integer.MAX_VALUE;
        int minInd = 0;
        int maxInd = 0;
        int n = nums.length;
        
        //First Find out the max and min element index
        for(int i=0;i<n;i++){
            if(nums[i]>max){
                max = nums[i];
                maxInd = i;
            }
            
            if(nums[i]<min){
                min = nums[i];
                minInd = i;
            }
        }
        
        //if both index are same then return the part in which less number of elements are there
        if(maxInd==minInd){
            return Math.min(maxInd+1,n-maxInd);
        }
        
        //max element is right side of min element
        if(maxInd>minInd){
            int count = Math.min(maxInd+1,n-minInd); // min of all the elements till max element and all the elements to the right of min element
            int count1 = minInd+1+(n-maxInd); // all elements to the left of min and right of max
            return Math.min(count,count1); // min of both
        }
        // min element is right side of the max element
        else{
            int count = Math.min(minInd+1,n-maxInd);
            int count1 = maxInd+1+(n-minInd);
            return Math.min(count,count1);
        }
        
    }
}