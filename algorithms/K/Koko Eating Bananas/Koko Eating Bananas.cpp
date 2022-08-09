class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int mx=1000000001;
        
        
        int st=1;
        
        
        while(mx>st)
        {
            
            int k = ((mx+st)/2);
            
            int sum=0;
            
            for(int i =0 ;i < piles.size() ; i++)
            {
                sum+=ceil(1.0 *piles[i]/k);
            }
            
            if(sum>h)
            {
                st=k+1;
            }
            else
            {
                mx=k;
            }
            
        }
        
        
        return st;
        
        
        
    }
};
