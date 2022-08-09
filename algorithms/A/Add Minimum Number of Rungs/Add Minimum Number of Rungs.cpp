class Solution {
public:
    
    int addRungs(vector<int>& rungs, int dist) {
        int count=0;
        
        //represents the previous height
        int prevHeight=0;
        int diff;
        for(int i=0;i<rungs.size();i++)
        {
            diff=rungs[i]-prevHeight;
            if(diff>dist)
            {
                //the number of rungs needed to be inserted
                count+=(diff)/dist;
                //if the diference is divided by dist with 0 remainder then count may count-1 are needed
                //for example  [4] dist=2 here , (4-0)/2 =2 but (4-0)%2 == 0 so count decreases (count-1) the ans is [2,4]
                if((diff)%dist==0)
                    count--;
            }
            prevHeight=rungs[i];
        }
        return count;
    }
};
