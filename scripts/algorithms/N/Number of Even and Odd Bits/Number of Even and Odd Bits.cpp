// Runtime: 3 ms (Top 56.89%) | Memory: 7.50 MB (Top 98.08%)

class Solution {
public:
    vector<int> evenOddBit(int n) {
        int count=0;
        int evn=0;
        int odd=0;
        while(n)
        {
            
            if(n&1==1)
            {
                if(count%2==0)evn++;
                else odd++;
            }
                
                
            count++;
            n=n>>1;
        }
        return {evn,odd};
    }
};
