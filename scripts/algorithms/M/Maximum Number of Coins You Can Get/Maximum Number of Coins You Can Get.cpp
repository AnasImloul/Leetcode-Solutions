// Runtime: 294 ms (Top 6.88%) | Memory: 53.5 MB (Top 9.97%)
class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end(),greater<int>());
        int myPilesCount=0;
        int myPilesSum=0;
        int PilesSize=piles.size();
        int i=1;
        while(myPilesCount<(PilesSize/3))
        {

            myPilesSum+=piles[i];
            myPilesCount++;
            i+=2;
        }
        return myPilesSum;
    }
};