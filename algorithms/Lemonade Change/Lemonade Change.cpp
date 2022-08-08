class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int, int> m;
        
        int change = 0;
        for(int i = 0 ; i < bills.size(); i++)
        {
            m[bills[i]]++;
            
            if(bills[i] > 5)
            {
                change = bills[i] - 5;
                
                if(change == 5)
                {
                    if(m[5] > 0)
                    {
                        m[5]--;
                    }
                    else
                    {
                        return false;
                    }
                }
                //change = 10
                else
                {
                    if(m[10] > 0 and m[5] > 0)
                    {
                        m[10]--;
                        m[5]--;
                    }
                    else if(m[5] >= 3)
                    {
                        m[5] -= 3;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
        
        return true;
    }
};
