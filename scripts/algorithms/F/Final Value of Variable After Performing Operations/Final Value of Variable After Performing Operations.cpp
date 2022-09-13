// Runtime: 23 ms (Top 13.24%) | Memory: 14 MB (Top 57.66%)
class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations)
    {
        int X = 0;
        for(int i=0;i<operations.size();i++)
        {
            if(operations[i]=="X++")
            {
                X++;
            }
            else if(operations[i] == "++X")
            {
                ++X;
            }
            else if(operations[i] == "X--")
            {
                X--;
            }
            else if(operations[i] == "--X")
            {
                --X;
            }
        }
        return X;
    }
};