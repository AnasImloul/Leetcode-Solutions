unordered_map<int, string> mp_0 = {{1, "One "},{2, "Two "},{3, "Three "},{4, "Four "},  {5, "Five "},{6, "Six "},{7, "Seven "},{8, "Eight "},{9, "Nine "}, {10, "Ten "},{11,"Eleven "},{12, "Twelve "},{13, "Thirteen "},{14, "Fourteen "},{15, "Fifteen "},{16, "Sixteen "},{17, "Seventeen "},{18, "Eighteen "},{19, "Nineteen "}};
        
unordered_map<int, string> mp_10 = {{20, "Twenty "},{30, "Thirty "},{40 , "Forty "},{50, "Fifty "},{60, "Sixty "},{70, "Seventy "},{80, "Eighty "},{90, "Ninety "}};

class Solution {
    
    void Solve2(string &ans , int num)
    {
       ans = mp_0[num] + ans;
    }
    
    void Solve( string &ans, int num)
    {
        int factor = 1;
        for(int i = 0 ; num>0 ; i++)
        {
            if(factor == 1)
            {
                
                if(num%100 < 20)
                {
                    Solve2(ans, num%100);
                    factor = factor*10;
                    num = num/10;
                }
                else
                {
                if(num%10 !=0)
                ans = mp_0[num%10] + ans;   
                }
            }
            
            else if(factor == 10)
            {
                if(num%10 != 0)
                   ans = mp_10[(num%10)*10] + ans;   
            }
            
            else if(factor == 100)
            {
                if(num%10 != 0)
                    ans = (mp_0[num%10] + "Hundred ") + ans;            
            }
            
            factor = factor*10;
            num = num/10;
        }
    }
public:
    string numberToWords(int num) {
        //2,147,483,647
        
        if(num == 0)
            return "Zero";
        
        string ans ;
        
       
        for(int i = 0 ; num>0 ; i++)
        {   
            if(i == 1)   
           { 
             if(num%1000>0)
             ans = "Thousand "+ ans;
           }
            else if(i == 2)
           { 
             if(num%1000>0)
             ans = "Million "+ ans;
           }
            else if( i == 3)
             ans = "Billion "+ ans;
            
            Solve(ans, num%1000);
            num = num/1000;
          
        }
                ans.pop_back();
        return ans;
        
        
    }
};
