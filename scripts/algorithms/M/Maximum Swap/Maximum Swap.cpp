// Runtime: 0 ms (Top 100.00%) | Memory: 5.8 MB (Top 87.89%)
class Solution {
public:
    int maximumSwap(int num) {
        string st_n=to_string(num);
        int maxNum=-1,maxIdx=-1;
        int leftidx=-1,rightidx=-1;
        for(int i=st_n.size()-1;i>=0;i--)
        {
            if(st_n[i]>maxNum)
            {
                maxNum=st_n[i];
                maxIdx=i;
                continue;
            }

            if(st_n[i]<maxNum)
            {
                leftidx=i;
                rightidx=maxIdx;
            }
        }
        if(leftidx==-1)
            return num;

        swap(st_n[leftidx],st_n[rightidx]);
        return stoi(st_n);
    }
};
