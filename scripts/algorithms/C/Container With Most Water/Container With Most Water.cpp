// Runtime: 1 ms (Top 58.53%) | Memory: 62.90 MB (Top 30.35%)

class Solution {
public:
    int maxArea(vector<int>& height) {
        int frontHeight, rareHeight, minHeight, area, distance;
        
        int front = 0;
        int rare = height.size() - 1;
        int maxArea = 0;
        
        while(front < rare)
        {
            frontHeight = height[front];
            rareHeight = height[rare];
                        
            if(frontHeight<rareHeight) minHeight = frontHeight;
            else minHeight = rareHeight;
            
            distance = rare - front;
            area = minHeight * distance;
                
            if(area > maxArea) maxArea = area;
            
            if(frontHeight > rareHeight) rare--;
            else front++;
        }
        
        return maxArea;
    }
};
