class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) 
    {
        int n = bits.size();
        if(n == 1)
            return true;
       
        int i = 0;
        while(i <= n - 2)
        {
            if(bits[i] == 0)
                i++;
            else 
                i = i + 2;
        }
        if(i <= n-1)
            return true;
        else 
            return false;
        
    }
};
