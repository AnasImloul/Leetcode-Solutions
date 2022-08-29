// Runtime: 7 ms (Top 77.52%) | Memory: 56 MB (Top 40.18%)
class Solution {
    public void wiggleSort(int[] nums) {
        int a[]=nums.clone();
        Arrays.sort(a);
        int left=(nums.length-1)/2;
        int right=nums.length-1;
        for(int i=0;i<nums.length;i++){
            if(i%2==0){
                nums[i]=a[left];
                left--;
            }
            else{
                nums[i]=a[right];
                right--;
            }
        }
    }
}