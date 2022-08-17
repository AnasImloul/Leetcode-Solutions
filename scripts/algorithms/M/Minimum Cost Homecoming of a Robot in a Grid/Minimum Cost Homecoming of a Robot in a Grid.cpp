// This is Straightforward Question becuase you need to travel at least one time the incoming rows and column in path.
// So why you need to complicate the path just traverse staright and to homePos Row and homePos column and you will get the ans...
// This Question would have become really tough when negative values also possible in the row and column vectors because that negative values could have decresed the results...but here its simple and concise.
class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int ans = 0;
        if(startPos[0] < homePos[0])
        {
            for(int i = startPos[0]+1 ; i <=homePos[0] ; i++)
            {
                ans+=rowCosts[i];
            }
        }
        if(startPos[0] > homePos[0])
        {
            for(int i = startPos[0]-1 ; i >=homePos[0] ; i--)
            {
                ans+=rowCosts[i];
            }
        }
        if(startPos[1] < homePos[1])
        {
            for(int i = startPos[1]+1 ; i <=homePos[1] ; i++)
            {
                ans+=colCosts[i];
            }
        }
         if(startPos[1] > homePos[1])
        {
            for(int i = startPos[1]-1 ; i >=homePos[1] ; i--)
            {
                ans+=colCosts[i];
            }
        }
        return ans;
    }
};
