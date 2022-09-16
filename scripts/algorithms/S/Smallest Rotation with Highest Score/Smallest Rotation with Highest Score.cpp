// Runtime: 348 ms (Top 19.35%) | Memory: 77.3 MB (Top 21.94%)
class Solution {
public:
    int bestRotation(vector<int>& nums) {
        int sz=nums.size();
        vector<int>pointsForIShifts(2*sz+1,0);
        for(int i=0;i<sz;i++){
            int l=0,h=0;
            if(nums[i]<=i){
                l=0;h=i-nums[i];
                pointsForIShifts[l]+=1;pointsForIShifts[h+1]-=1;
            }
            l=i+1;h=i+sz-nums[i];
            pointsForIShifts[l]+=1;pointsForIShifts[h+1]-=1;
        }
        int maxP=pointsForIShifts[0],k=0;
        for(int i=1;i<pointsForIShifts.size();i++){
            pointsForIShifts[i]+=pointsForIShifts[i-1];
            if(pointsForIShifts[i]>maxP){
                maxP=pointsForIShifts[i];
                k=i;
            }
        }
        return k;
    }
};