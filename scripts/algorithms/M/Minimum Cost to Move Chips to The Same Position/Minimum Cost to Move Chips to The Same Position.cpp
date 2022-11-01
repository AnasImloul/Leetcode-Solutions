// Runtime: 9 ms (Top 9.81%) | Memory: 7.4 MB (Top 10.15%)
class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int even=0,odd=0;
        for(int i=0;i<position.size();i++)
        {
                if(position[i]%2==0)
                    even++;
                else
                    odd++;

        }
        return min(odd,even);
    }
};