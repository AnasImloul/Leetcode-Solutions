class Solution {
    public int findLengthOfShortestSubarray(int[] arr) {
        int firstLast=0,lastFirst=arr.length-1;
        for(;firstLast<arr.length-1;firstLast++){
            if(arr[firstLast]>arr[firstLast+1]) break;
        }
		//Base case for a non-decreasing sequence
        if(firstLast==arr.length-1) return 0;
        for( ;lastFirst>0;lastFirst--){
            if(arr[lastFirst]<arr[lastFirst-1]) break;
        }
		//Possibilities 1 or 2 as mentioned above
        int minLength=Math.min(arr.length-firstLast-1,lastFirst);
        for(;firstLast>=0;firstLast--){
            for(int i=lastFirst;i<arr.length;i++){
                if(arr[firstLast]>arr[i]) continue;
                minLength = Math.min(minLength,i-firstLast-1);
                break;
            }
        }
        return minLength;
    }
}
