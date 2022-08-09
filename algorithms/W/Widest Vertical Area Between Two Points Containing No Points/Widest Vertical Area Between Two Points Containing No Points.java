class Solution {
    public int maxWidthOfVerticalArea(int[][] points) {
        int L = points.length;
        // y-coordinate of a point does not matter in width
        int arr[] = new int[L];
        for(int i=0;i<L;i++){
            arr[i]=points[i][0];
        }
        Arrays.sort(arr);
        
        int diff = Integer.MIN_VALUE;
        
        for(int i=1;i<L;i++){
            if((arr[i]-arr[i-1])>diff){
                diff=arr[i]-arr[i-1];
            }
        }
        return diff;
    }
}
