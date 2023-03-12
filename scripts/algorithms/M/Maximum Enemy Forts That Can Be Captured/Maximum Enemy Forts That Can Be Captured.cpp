class Solution {
public:
    int captureForts(vector<int>& forts) {
        vector<int>cmd;
        vector<int>arm;
        int start_1=-1,start_m1=-1;
        int ans=-1;
        for(int i=0;i<forts.size();i++)
        {
            if(forts[i]==1)
            {
                if(start_m1!=-1)
                {
                    ans=max(ans,i-start_m1-1);
                    start_m1=-1;
                }
                start_1=i;
            }
            else if(forts[i]==-1)
            {
                if(start_1!=-1)
                {
                    ans=max(ans,i-start_1-1);
                    start_1=-1;
                }
                start_m1=i;
            }
            
        }
        if(ans==-1)return 0;
        return ans;
    }
};