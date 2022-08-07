class Solution {
    public int trap(int[] height) {
        int left = 0;
        int right = height.length - 1;
        
        int l_max = height[left];
        int r_max = height[right];
        int res = 0;
        
        while(left < right) {
            if(l_max < r_max) {
                left+=1;
                l_max = Math.max(l_max, height[left]);
                res += l_max - height[left];
            }
            else{
                right-=1;
                r_max = Math.max(r_max, height[right]);
                res += r_max - height[right];
            }
        }
        
        return res;
    }
}
