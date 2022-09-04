// Runtime: 386 ms (Top 8.00%) | Memory: 45.9 MB (Top 26.80%)
class Solution {
public:

    //N--> left(-2):W, right(-1):E
    //S--> left:E, right:W
    //E--> left:N, right:S
    //W--> left:S, right:N

    vector<vector<int>> change= { //for direction change
        {3,2},
        {2,3},
        {0,1},
        {1,0}
    };

    vector<vector<int>> sign = { //signs for x and y coordinates movement
        {0,1},//North
        {0,-1},//south
        {1,0},//east
        {-1,0}//west
    };

    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<vector<int>> s;
        for(int i = 0;i<obstacles.size();i++){
            s.insert(obstacles[i]);
        }
        int direction = 0;
        int ans = 0;
        int xi = 0,yi = 0;
        for(int i = 0;i<commands.size();i++){
            if(commands[i]<=9 && commands[i]>=1){
                int signx = sign[direction][0];
                int signy = sign[direction][1];
                while(commands[i]){
                    xi += signx;
                    yi += signy;
                    if(s.count({xi,yi})){
                        xi -= signx;
                        yi -= signy;
                        break;
                    }
                    commands[i]--;
                }
            }
            else{
                direction = change[direction][commands[i]+2];
            }
            ans = max(ans,xi*xi+yi*yi);
        }
        return ans;
    }
};