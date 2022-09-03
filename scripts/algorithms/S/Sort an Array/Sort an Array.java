// Runtime: 35 ms (Top 28.44%) | Memory: 75.6 MB (Top 11.81%)
class Solution {

        public void downHeapify(int[] nums, int startIndex, int lastIndex){

        int parentIndex = startIndex;
        int leftChildIndex = 2*parentIndex + 1;
        int rightChildIndex = 2*parentIndex + 2;

        while(leftChildIndex <= lastIndex){
            int maxIndex = parentIndex;
            if(nums[leftChildIndex] > nums[maxIndex]){
                maxIndex = leftChildIndex;
            }
            if(rightChildIndex <= lastIndex && nums[rightChildIndex] > nums[maxIndex]){
                maxIndex = rightChildIndex;
            }
            if(maxIndex == parentIndex){
                return;
            }
            int temp = nums[maxIndex];
            nums[maxIndex] = nums[parentIndex];
            nums[parentIndex] = temp;
            parentIndex = maxIndex;
            leftChildIndex = 2*parentIndex + 1;
            rightChildIndex = 2*parentIndex + 2;
        }
        return;
    }

    public int[] sortArray(int[] nums) {
        int len = nums.length;
        //building a heap - O(n) time
        for(int i=(len/2)-1;i>=0;i--){
            downHeapify(nums,i,len-1);
        }
        //sorting element - nlogn(n) time
        for(int i=len -1 ;i>0;i--){
             int temp = nums[i];
             nums[i] = nums[0];
             nums[0] = temp;
             downHeapify(nums,0,i-1);
        }
        return nums;

    }
}