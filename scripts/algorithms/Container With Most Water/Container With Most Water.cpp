class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0,right=height.size()-1,ans=0;
        while(left<right){
            int w=right-left;
            int h=min(height[left],height[right]);
            ans=max(ans,h*w);
            if(height[left]<height[right])left++;
            else if(height[left]>height[right])right--;
            else{
                right--;
                left++;
            }
        }
        return ans;
    }
};
