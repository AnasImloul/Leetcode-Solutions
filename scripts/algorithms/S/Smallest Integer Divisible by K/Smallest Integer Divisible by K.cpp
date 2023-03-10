class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k&1==0)return -1;
        long long val=0;

        for(int i=1; i<=k;i++)
        {
            // val=((val*10)+1);
            if((val=(val*10+1)%k)==0)return i;
        }
        return -1;
        
        
        
    }
};