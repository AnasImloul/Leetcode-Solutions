class Solution {
public:
    bool valid(int n)
    {
        vector<int> map(10,0);
        while(n)
        {
            int rem = n%10;
            map[rem]++;
            n = n/10;
        }
        for(int i=0; i<10; i++)
            if(map[i] && map[i]!=i) return false;
        return true;
    }
    
    int nextBeautifulNumber(int n) {
     
        while(true) 
        {
            ++n;
            if(valid(n))
                return n;
        }
        return 1;
    }
};