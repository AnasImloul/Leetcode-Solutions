// Runtime: 5 ms (Top 46.02%) | Memory: 50.6 MB (Top 18.35%)

class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        if(nums1.length==1 && nums2.length==1) return (double)(nums1[0]+nums2[0])/2.0;
        int i = 0;
        int j = 0;
        int k = 0;
        int nums[] = new int[nums1.length + nums2.length];
        if(nums1.length !=0 && nums2.length != 0){
          while(i < nums1.length && j < nums2.length){
            if(nums1[i] < nums2[j]){
                nums[k] = nums1[i];
                i++;
                k++;
            }else{
                nums[k] = nums2[j];
                j++;
                k++;
            }
          }
            while(i < nums1.length){
                nums[k] = nums1[i];
                i++;
                k++;
            }
             while(j < nums2.length){
                nums[k] = nums2[j];
                j++;
                k++;
            }
        }
        if(nums1.length==0){
            for(int h: nums2){
                nums[k] = h;
                k++;
            }
        }

        if(nums2.length==0){
            for(int d : nums1){
                nums[k] = d;
                k++;
            }
        }

        int mid = (nums.length / 2);

        if (nums.length % 2 == 0) {
            return ((double) nums[mid] + (double) nums[mid - 1]) / 2.0;
        } else {
            return nums[mid];
        }
    }
}