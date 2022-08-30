// Runtime: 0 ms (Top 100.00%) | Memory: 6.4 MB (Top 58.32%)
class Solution {
public:
    int countPoints(string rings) {

        int n=rings.length();
        //It is given that number of rod is 10 0 to 9 so we have to place ring any of these
        vector<int>vp(10,0);//store the no of rings
        for(int i=0;i<n;i+=2)
        {
            char col=rings[i];
            vp[rings[i+1]-'0']|=(col=='R'? 1: col =='G' ? 2 : 4);//checking for rings

        }
        int count=0;
        for(int i=0;i<10;i++)
        {
            if(vp[i]==7)
            {
                count++;
            }
        }
        return count;

    }
};