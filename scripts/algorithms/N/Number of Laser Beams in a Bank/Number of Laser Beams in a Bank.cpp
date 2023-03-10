class Solution {
public:
    int numberOfBeams(vector<string>& bank) 
    {
        int rowLaserCount=0,totalLaserCount=0,prevCount=0;
        for(int i=0;i<bank.size();i++)
        {
            rowLaserCount=0;
            for(char j:bank[i])
            {
              if(j=='1')  rowLaserCount++;
            }totalLaserCount+=(prevCount*rowLaserCount);
            if(rowLaserCount)prevCount=rowLaserCount;
        }
        return totalLaserCount;
        
    }
};