               class Solution {
public int threeSumClosest(int[] nums, int target) {
    int n=nums.length;
    int count=0;
    int sumone=0;
     int value =Integer.MAX_VALUE;
    Arrays.sort(nums);
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++ ){
            for(int k=j+1; k<n; k++){
                count= nums[i]+ nums[j]+ nums[k];
			   if(count==target){
                    return count;
                }
                 int diff = target-count;
             if(Math.abs(diff)<value){
                value=Math.abs(diff);
                sumone=count;
            }
        }
    }
}
    return sumone;
	}
