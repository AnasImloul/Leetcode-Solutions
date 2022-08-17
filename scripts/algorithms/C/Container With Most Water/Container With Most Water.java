class Solution {
    public int maxArea(int[] height) {
        int maxarea=0;
        int left = 0;
        int right = height.length - 1;
        while(left < right){
            int lh = height[left];
            int rh = height[right];
            int min_h = Math.min(lh,rh);
            maxarea = Math.max(maxarea,min_h*(right-left));
            if(lh<rh){
                left++;
            }else{
                right--;
            }
        }
        return maxarea;
    }
}