class Solution {
    public int numSubarrayProductLessThanK(int[] nums, int k) {
		//if k=0 then ans will always be zero as we have positive integers array only.
        if(k==0)
            return 0;
        
        int length = 0;
        long product = 1;
        int i = 0;
        int j = 0;
        int n = nums.length;
        int ans = 0;
        
        while(j<n){
            product*=nums[j];
			//Add the number to current window if the product is less than k and calculate no of subarrays using length only.
            if(product<k){
                length+=1;
                ans+=length;
            }
            else{
				//Remove element one by one till product becomes less than k.
                while(i<=j && product>=k){
                    product/=nums[i];
                    i++;
                }
				//As we have added only 1 element to the window and this element can make subarray to j-i element along with itself.
                ans+=(j-i)+1;
				//Update the current subarray length.
                length=j-i+1;
            }
            j++;
        }
        
        return ans;
    }
}
