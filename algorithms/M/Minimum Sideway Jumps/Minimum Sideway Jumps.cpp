class Solution {
public:
    int solve(vector<int>& obstacles, int pos, int lane)
    {
        if(pos == obstacles.size()-2)
            return 0;
        
        if(obstacles[pos+1]!=lane)
        {
            return solve(obstacles, pos+1, lane);
        }
        if(obstacles[pos+1]==lane){
            int l1=0, l2=0;
            if(lane==1)
            {
                l1=2;
                l2=3;
            }
            else if(lane==2)
            {
                l1=1;
                l2=3;
            }
            else{
                l1=1;
                l2=2;
            }
            if(obstacles[pos]==l1)
                return 1 + solve(obstacles, pos+1, l2);
            else if(obstacles[pos]==l2)
                return 1 + solve(obstacles, pos+1, l1);
            else
                return 1 + min(solve(obstacles, pos+1, l1), solve(obstacles, pos+1, l2));
        }
        return 0;
    }
    
    int minSideJumps(vector<int>& obstacles) {
        return solve(obstacles, 0, 2);
    }
};
