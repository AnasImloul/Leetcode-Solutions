class Solution {
public:
    int getLucky(string s, int k) {
        
        long long sum=0,d;
        string convert;
        
        for(auto& ch: s)
        {
            convert+= to_string((ch-96));
        }

        while(k--)
        {
            sum=0;
            for(auto& ch: convert)
            {
               sum+= (ch-48);
            }
            convert=to_string(sum);
        }
       
        return sum;
    }
};