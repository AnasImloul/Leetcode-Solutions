class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) 
    {    
        double tax = 0; 
        
        if(brackets[0][0]<=income) tax=(brackets[0][0]*brackets[0][1]/100.0);         
        else return (income*brackets[0][1]/100.0);
            
        for(int i=1; i<brackets.size(); i++)
        {
            if(brackets[i][0]<=income)
                    tax += ((brackets[i][0]-brackets[i-1][0])*brackets[i][1]/100.0);
            
            else 
            {
                tax += ((income-brackets[i-1][0])*brackets[i][1]/100.0);
                break;
            }
        }
        return tax;
        
    }
};
